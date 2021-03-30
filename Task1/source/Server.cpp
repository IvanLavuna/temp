//
// Created by ivan on 10.03.21.
//

#include "../include/Server.h"

Server::Server():
	m_socket(-1),
	m_sockAddress{}{}

Server::~Server()
{
	CloseSocket();
}

void Server::CreateServer(ushort port)
{
	CreateSocket();
	Bind(port);
}

void Server::CreateSocket()
{
	m_socket = socket(AF_INET, SOCK_STREAM,IPPROTO_TCP);
	if(m_socket == -1)
		throw ERROR_MESSAGE("Failed to create socket");
}

void Server::Bind(ushort port)
{
	m_sockAddress.sin_port = htons(port);
	m_sockAddress.sin_family = AF_INET;
	m_sockAddress.sin_addr.s_addr = inet_addr(LOCAL_HOST);
	if(bind(m_socket,(const sockaddr*) &m_sockAddress, sizeof m_sockAddress) == -1)
		throw ERROR_MESSAGE("Failed to bind socket with address");
}

void Server::Listen()
{
	if(listen(m_socket, SOMAXCONN) == -1)
		throw ERROR_MESSAGE("Failed to enter listening state");
}

void Server::Run()
{
	// entering listening state
	Listen();
	// log
	std::cout << "Server is in listening state...\n";

	sockaddr_in clientAddr;
	socklen_t cliSockLen = sizeof clientAddr;

	int clientSockID = accept(m_socket, (sockaddr *) &clientAddr, &cliSockLen);
	if (clientSockID == -1)
	{
		cerr << "Server Failed to accept.\n";
		return;
	}
	// log status
	cout << "Connection successfully established.\n";
	ProcessClient(clientSockID,clientAddr,cliSockLen);
}

void Server::ProcessClient(ushort clientSockID, sockaddr_in& clientAddr, socklen_t& cliSockLen)
{
	char buf[BUF_SZ];
	string str_buf;

	while(true)
	{
		// clear buffer
		memset(buf,0, BUF_SZ);

		// wait for a message
		int message_sz = recv(clientSockID, buf, BUF_SZ,0);
		str_buf = string(buf);

		if(message_sz == -1)
		{
			std::cerr << "The are some problems with network...\n";
			break;
		}
		else if(message_sz == 0)
		{
			std::cerr << "Client disconnected\n";
			break;
		}
		else if(str_buf.substr(0,8) == "NewPort-")
		{
			ushort new_port = stoi(string(buf).substr(8));
			if(IsAvailable(new_port))
			{ // socket recreation. Some cooperation with client
				strcpy(buf,"success");
				send(clientSockID,buf,strlen(buf),0);
				close(clientSockID);
				CloseSocket();

				CreateServer(new_port);
				Listen();
				clientSockID = accept(m_socket,(sockaddr*) &clientAddr,&cliSockLen);
				// log
				cout << "Port successfully changed.\n";
			}
			else
			{
				// port failed
				strcpy(buf,"failre");
				send(clientSockID,buf,strlen(buf) + 1,0);
				cout << "Port is NOT changed.\n";
			}
		}
		else
		{
			// log
			std::cout << str_buf << '\n';
			// sending message back
			send(clientSockID, buf, strlen(buf), 0);
		}
	}
	// closing client
	close(clientSockID);
}

bool Server::IsAvailable(ushort port)
{
	ushort sock = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	sockaddr_in addr{};
	addr.sin_port = htons(port);
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = inet_addr(LOCAL_HOST);
	if(bind(sock,(const sockaddr*)&addr,sizeof addr) == -1)
	{
		close(sock);
		return false;
	}
	close(sock);
	return true;

}

void Server::CloseSocket()
{
	close(m_socket);
}


//
// Created by ivan on 10.03.21.
//

#include "../include/Client.h"

Client::Client(Logger logger):
	m_hostSock(-1),
	m_hostSockAddr{},
	m_logger(logger){}

Client::~Client()
{
	CloseHostSocket();
}


void Client::Run()
{
	char buf[BUF_SZ];
	string buf_str;
	while(true)
	{
		// clearing buffer
		memset(buf,0,BUF_SZ);
		// clearing console
		cout << ">> ";
		getline(std::cin,buf_str);
		strcpy(buf,buf_str.c_str());

		if(buf_str == "quit")
			break;
		else if(buf_str.substr(0,8) == "NewPort-")
		{
			/// new port
			send(m_hostSock,buf_str.c_str(),(int) buf_str.size(),0);
			recv(m_hostSock,buf,BUF_SZ,0);
			buf_str = string(buf);
			if(buf_str.substr(0,7) == "success")
			{
				ushort new_port = std::stoi(buf_str.substr(8));
				Disconnect();
				CreateHostSocket();
				clock_t begin = clock(), end;
				bool connection = true;
				while(!Connect(LOCAL_HOST,new_port))
				{  /// wait 3 seconds
					end = clock();
					if(double(end - begin) / CLOCKS_PER_SEC >= 3)
					{
						cout << "Connection failed. Exit\n";
						connection = false;
						break;
					}
				}
				if(connection)
					cout << "success\n";
				else break;
			}
			else
			{
				cout << "failre\n";
			}
		}
		else
		{ /// send and receive
			send(m_hostSock, buf_str.c_str(), (int) buf_str.size(), 0);
			recv(m_hostSock, buf, BUF_SZ, 0);
			// write response to console
			cout << buf << '\n';
		}
	}
}

bool Client::Connect(string &&host_ip, ushort host_port)
{
	m_hostSockAddr.sin_family = AF_INET;
	m_hostSockAddr.sin_port = htons(host_port);
	m_hostSockAddr.sin_addr.s_addr = inet_addr(LOCAL_HOST);

	// convert IPv4 or IPv6 addresses from text to binary form
	if(inet_pton(AF_INET, host_ip.c_str(), &m_hostSockAddr.sin_addr) < 0)
		return false;

	if(connect(m_hostSock,(const sockaddr*)&m_hostSockAddr,sizeof m_hostSockAddr) == -1)
		return false;

	if(m_logger == CONSOLE)
	{ // log
		cout << "Connection to host: " << host_ip << " on port: " << host_port << " established.\n";
	}
	return true;
}

void Client::Disconnect()
{
	CloseHostSocket();
}

void Client::CreateHostSocket()
{
	m_hostSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(m_hostSock == -1)
		throw ERROR_MESSAGE("Failed to create host socket\n");
}

void Client::CloseHostSocket() noexcept
{
	close(m_hostSock);
}

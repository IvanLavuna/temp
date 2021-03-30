//
// Created by ivan on 10.03.21.
//

#ifndef DYNAMIC_COMMUNICATION_SERVER_H
#define DYNAMIC_COMMUNICATION_SERVER_H

#include "Base.h"
#include "Client.h"
using std::string;

/**
	Default Server Parameters:
 Port: 7300
 domain: AF_INET
 type: SOCK_STREAM
 protocol: TCP
 max connections at the same time : 10
*/

class Server
{
private:

	/// variables
	int m_socket;
	sockaddr_in m_sockAddress;

	/// methods
	void ProcessClient(ushort clientSockID, sockaddr_in& clientAddr, socklen_t& cliSockLen);
	void CreateSocket();
	void CloseSocket();
	void Bind(ushort port);
	void Listen();
	/** to check if port is available or not **/
	bool IsAvailable(ushort port);
public:
	/** constructor / destructor **/
	Server();
	~Server();

	/** core **/
	void CreateServer(ushort port = DEFAULT_HOST_PORT);
	void Run();
};


#endif //DYNAMIC_COMMUNICATION_SERVER_H

//
// Created by ivan on 10.03.21.
//

#ifndef DYNAMIC_COMMUNICATION_CLIENT_H
#define DYNAMIC_COMMUNICATION_CLIENT_H

#include "Base.h"

/**
 * Protocol : TCP
 */
class Client
{
public:
	/// TODO : implement FILE log(maybe logging should be handled by some
	///  LOG class)
	enum Logger {CONSOLE, NO_LOG};

private:
	/** variables **/
	int 		m_hostSock;
	sockaddr_in m_hostSockAddr;
	Logger		m_logger;

public:
	/** constructor / destructor **/
	Client(Logger logger = CONSOLE);
	~Client();

	/** core **/
	void CreateHostSocket();
	void CloseHostSocket() noexcept;

	/** Connects to specified host with specified IP
	 * @return true in case of success otherwise false **/
	bool Connect(string&& host_ip, ushort host_port = DEFAULT_HOST_PORT);
	/** Creates user-console mode(reading user commands from console)
	 * ! Client must be connected to some host **/
	void Run();
	/** Closes host socket **/
	void Disconnect();

};


#endif //DYNAMIC_COMMUNICATION_CLIENT_H

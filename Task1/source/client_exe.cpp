//
// Created by ivan on 16.03.21.
//
#include "Client.h"

int main()
{
	Client my_client;
	try
	{
		my_client.CreateHostSocket();
		my_client.Connect(LOCAL_HOST, DEFAULT_HOST_PORT);
		my_client.Run();
	}
	catch (const char *msg)
	{
		std::cerr << "Exception: " << msg << '\n';
	}
}
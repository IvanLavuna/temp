//
// Created by ivan on 16.03.21.
//
#include "Server.h"

int main()
{
	Server my_server;
	try
	{
		my_server.CreateServer();
		my_server.Run();
	}
	catch (std::exception& exc)
	{
		cerr << "Exception: " << exc.what() << '\n';
	}
	catch (const char * msg)
	{
		std::cerr << "Exception: " << msg << '\n';
	}
}
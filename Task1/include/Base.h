//
// Created by ivan on 10.03.21.
//

#ifndef DYNAMIC_COMMUNICATION_BASE_H
#define DYNAMIC_COMMUNICATION_BASE_H


/** network**/
#include <sys/socket.h>
#include <netinet/in.h> /// Defines Internet protocol and address family
#include <sys/un.h> /// Used for local communication between programs running on the same computer.
#include <arpa/inet.h> /// Functions for manipulating numeric IP addresses.
#include <netdb.h> /// Functions for translating protocol names and host names into numeric addresses. Searches local data as well as name services.
#include <unistd.h>
#include <thread>

/** standard libraries **/
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <ctime>

#define DEFAULT_HOST_PORT 7300
#define LOCAL_HOST "192.168.0.114"
#define BUF_SZ 2048

#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)
#define AT __FILE__ ":" TOSTRING(__LINE__)
#define ERROR_MESSAGE(DESC) ("error: " AT "\n" "Description: " DESC "\n")

using std::string;
using std::cout;
using std::cerr;

#endif //DYNAMIC_COMMUNICATION_BASE_H

# Dynamic_Communication

Client/Server application for dynamic text communication
Prerequisites: cmake, make;
Main functionality is port changing.
Program is only developed for Unix system(Linux, MAC)
In order to run project do:
 >> git clone https://gitlab.com/LaVuna47/dynamic_communication.git
 >
 >> cd dynamic_communication 
 >
 >> mkdir build
 > 
 >> cd build
 > 
 >> cmake ../
 > 
 >> make
 
For know you have build two executables: client and server
Now run server using command
 >>  ./server

Open another terminal in build directory and run client
 
 >> ./client 

Now Client can use NewPort-[port] like 
 >> NewPort-7832
 
to change port of communication and quit command to end process
All other commands will be resend back from server
You can use command 
>> sudo lsof -i -P -n

to see all ports that are currently working on 
cmake_minimum_required(VERSION 3.17)
project(dynamic_communication)

set(CMAKE_CXX_STANDARD 14)


include_directories(include source)


add_executable(client source/Client.cpp source/client_exe.cpp)
add_executable(server source/Server.cpp source/server_exe.cpp)

#target_link_libraries(server -lpthread)
#target_link_libraries(client -lpthread)




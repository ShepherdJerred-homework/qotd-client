cmake_minimum_required(VERSION 3.9)
project(qotd_client)

set(CMAKE_CXX_STANDARD 17)

add_executable(qotd_client main.cpp qotd.h qotd.cpp connectsock.cpp UDP_send.cpp UDP_recv.cpp)
cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

project(hz)

set(CMAKE_CXX_STANDARD 17)

add_library(lib
	User.cpp User.h
	Message.cpp Message.h 
	Database.cpp Database.h)

add_executable(rez main.cpp)

target_link_libraries(rez lib)




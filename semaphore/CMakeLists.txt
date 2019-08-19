cmake_minimum_required(VERSION 2.8)
project(demo)
set(sources main.cpp
	Semaphore.cpp)
add_executable(${PROJECT_NAME} ${sources})

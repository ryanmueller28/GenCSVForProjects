cmake_minimum_required(VERSION 3.13)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD True)

if(UNIX)
	project(GenCustomerCSV)
endif(UNIX)

set(include_files
	src/*.h)

file(GLOB SOURCES
	src/*.cpp)

if (UNIX)
	add_executable(GenCustomerCSV ${SOURCES})
endif(UNIX)

cmake_minimum_required(VERSION 3.10)

project(MicroService)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20 -Wall -Wextra -pedantic -g")

find_package(httplib REQUIRED)

set(SOURCE_FILES main.cpp service.cpp)

add_executable(MicroService ${SOURCE_FILES})

target_link_libraries(MicroService httplib::httplib)
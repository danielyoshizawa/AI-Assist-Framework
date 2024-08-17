cmake_minimum_required(VERSION 3.10)

project(MicroService)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20 -Wall -Wextra -pedantic -g")

find_package(httplib REQUIRED)

add_subdirectory(src AiAssistFramework)
add_subdirectory(test MicroService)
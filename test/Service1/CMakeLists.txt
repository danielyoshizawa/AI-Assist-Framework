cmake_minimum_required(VERSION 3.10)

set(SOURCE_FILES main.cpp)

add_executable(Service1 ${SOURCE_FILES})

target_link_libraries(Service1 AiAssistFramework)
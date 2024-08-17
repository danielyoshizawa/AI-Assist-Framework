cmake_minimum_required(VERSION 3.10)

set(SOURCE_FILES main.cpp)

add_executable(Test ${SOURCE_FILES})

target_link_libraries(Test AiAssistFramework)
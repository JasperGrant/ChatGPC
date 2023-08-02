cmake_minimum_required(VERSION 3.22)
project(ChatGPC C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

find_package(CURL CONFIG REQUIRED)

add_executable(ChatGPC
        ChatGPC.c
        ChatGPC.h
        tests/tests.c)

target_link_libraries(ChatGPC PRIVATE CURL::libcurl)


cmake_minimum_required(VERSION 3.15)
project(h3 C)

set(CMAKE_C_STANDARD 99)

add_executable(h3 main.c aes.h aes.c)
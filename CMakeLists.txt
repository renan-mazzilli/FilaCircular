cmake_minimum_required(VERSION 3.27.8)
project(FilaCircular C)

set(CMAKE_C_STANDARD 11)

add_executable(FilaCircular main.c
        FilaCircular.h
        FilaCircular.c)

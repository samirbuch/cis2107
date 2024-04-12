cmake_minimum_required(VERSION 3.27)
project(string_lib C)

set(CMAKE_C_STANDARD 11)

add_executable(string_lib main.c
        lib/strlen.c
        lib/str_utils.h
        lib/all_letters.c
        lib/num_in_range.c
        lib/diff.c)

cmake_minimum_required(VERSION 3.27)
project(string_lib C)

set(CMAKE_C_STANDARD 11)

add_executable(string_lib main.c
        lib/reimpl/s_strlen.c
        lib/str_utils.h
        lib/all_letters.c
        lib/num_in_range.c
        lib/diff.c
        lib/shorten.c
        lib/len_diff.c
        lib/rm_left_space.c
        lib/rm_right_space.c
        lib/rm_space.c
        lib/find.c
        lib/util/strequal.c
        lib/ptr_to.c
        lib/is_empty.c
        lib/str_zip.c
        lib/capitalize.c
        lib/reimpl/tolower.c
        lib/reimpl/toupper.c
        lib/reimpl/s_tolower.c
        lib/reimpl/s_toupper.c
        lib/reimpl/reimpl.h
        lib/replace.c
        lib/reimpl/strcpy.c
)

//
// Created by Samir Buch on 4/11/24.
//

#include "../str_utils.h"

size_s s_strlen(const char* str) {
    size_s length = 0;
    while(*(str++) != '\0')
        length++;
    return length;
}

size_s s_strnlen(const char* str, size_s n) {
    size_s length = 0;
    while(*(str++) != '\0' && length != n)
        length++;
    return length;
}
//
// Created by Samir Buch on 4/11/24.
//

#include "../str_utils.h"

size_t s_strlen(const char* str) {
    size_t length = 0;
    while(*(str++) != '\0')
        length++;
    return length;
}

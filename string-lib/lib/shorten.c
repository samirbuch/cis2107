//
// Created by Samir Buch on 4/12/24.
//

//#include <stdio.h>
#include "str_utils.h"

void shorten(char* s, int new_len) {
    size_s length = s_strlen(s);
    if(length <= new_len) return;

    *(s + new_len + 1) = '\0';
    // Place the null terminator at the string's new length + 1
    // This doesn't shorten the string in memory i.e. doesn't literally make the string shorter,
    // but it *does* reduce the visibility by anybody who cares.

//    printf("shortened string: %s\n", s);
}
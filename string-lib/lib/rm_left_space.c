//
// Created by Samir Buch on 4/13/24.
//

#include "str_utils.h"

void rm_left_space(char *s) {
    char *sHead = s;

    while (*s == ' ') {
        s++;
    }

    while (*s != '\0') {
        *sHead = *s;
        s++;
        sHead++;
    }

    *sHead = '\0';
}
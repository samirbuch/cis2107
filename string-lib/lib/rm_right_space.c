//
// Created by Samir Buch on 4/18/24.
//

#include "str_utils.h"

void rm_right_space(char *s) {
    size_s length = s_strlen(s);

    char *sTail = s + length - 1;
    s = sTail;

    while (*s == ' ') {
        s--;
    }
    s++;

    *s = '\0';
}
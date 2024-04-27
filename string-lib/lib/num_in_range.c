//
// Created by Samir Buch on 4/11/24.
//

#include "str_utils.h"

size_t num_in_range(const char *s1, char b, char t) {
    size_t length = s_strlen(s1);

    int c = 0;
    for(int i = 0; i < length; i++) {
        char s = s1[i];
        if(s >= b && s <= t) c++;
    }

    return c;
}
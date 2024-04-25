//
// Created by Samir Buch on 4/25/24.
//

#include "str_utils.h"

void take_last(char *s, int n) {
    // Make all the characters up to the last n characters each spaces,
    for(int i = 0; i < s_strlen(s) - n; i++) {
        s[i] = ' ';
    }
    // then remove the left spaces.
    rm_left_space(s);

    // omegalul
}
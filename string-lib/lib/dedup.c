//
// Created by Samir Buch on 4/25/24.
//

#include <stdlib.h>
#include "str_utils.h"

char *dedup(const char *s) {
    size_t sLen = s_strlen(s);

    char *new_buffer = calloc(128, sizeof(char)); // realistically, char should always be size 1. but you never know.

    int ascii_frequency[127] = { 0 };

    int buff_index = 0;
    for(int i = 0; i < sLen; i++) {
        char c = s[i];
        if(ascii_frequency[c] == 0) {
            ascii_frequency[c]++;
            new_buffer[buff_index++] = c;
        }
    }

    // Set the last character
    new_buffer[++buff_index] = '\0';

    return new_buffer;
}
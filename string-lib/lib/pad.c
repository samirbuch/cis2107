//
// Created by Samir Buch on 4/25/24.
//

#include <stdlib.h>
#include "str_utils.h"

char *pad(const char *s, size_s d) {
    size_s sLen = s_strlen(s);

    // Find the next even multiple of d
    size_s next_even_multiple = sLen;
    while(!(next_even_multiple % d == 0 && next_even_multiple % 2 == 0)) {
        next_even_multiple++;
    }

    size_s padding_amount = next_even_multiple - sLen;

    char *buffer = calloc(sLen + padding_amount, sizeof(char));
    s_strncpy(buffer, s, sLen); // cut off the '\0'
    buffer += sLen; // seek buffer by sLen
    for(size_s i = sLen; i < sLen + padding_amount; i++) {
        *(buffer++) = ' ';
    }
    *(++buffer) = '\0'; // and cap it off with a null <3

    // rewind the buffer
    buffer -= sLen + padding_amount + 1;

    return buffer;
}
//
// Created by Samir Buch on 4/25/24.
//

#include <stdlib.h>
#include "str_utils.h"

char *repeat(char *s, int x, char sep) {
    size_s sLen = s_strlen(s);

    // Number of times sLen is being repeated plus number of times the separator is being repeated
    // plus one for the null character
    size_s total_length = sLen * x + (sep * x - 1) + 1;
    char *buffer = calloc(total_length, sizeof(char));
    buffer[total_length] = '\0';

    // Repeat the string s
    for(int i = 0; i < x; i++) {
        // Read the string to be repeated into the proper location in the buffer
        for(int sIndex = 0; sIndex < sLen; sIndex++) {
            buffer[sIndex + (i * sLen) + i] = s[sIndex];
            // I'm sure this would be way easier if I reimplemented strcat but i CBA
        }
        // Insert the separator
        if(i != x - 1) // only if we're not in the last iteration
            buffer[i + ((i + 1) * sLen)] = sep;
    }

    return buffer;
}
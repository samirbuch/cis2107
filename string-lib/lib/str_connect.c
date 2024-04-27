//
// Created by Samir Buch on 4/26/24.
//

#include <stdlib.h>
#include "str_utils.h"

char *str_connect(char **strs, int n, char c) {
    size_s bufferLength = 0;

    // Count up how many characters we're going to create a buffer for
    for (int i = 0; i < n; i++) {
        bufferLength += s_strlen(strs[i]);
    }
    bufferLength += n - 1; // Separators

    char *buffer = calloc(bufferLength + 1, sizeof(char));

    size_s used = 0;
    for(int curWordIdx = 0; curWordIdx < n; curWordIdx++) {
        char *currentWord = strs[curWordIdx];
        size_s curWordLen = s_strlen(currentWord);
        for(int i = 0; i < curWordLen; i++) {
            buffer[used++] = currentWord[i];
        }

        if(curWordIdx != n - 1)
            buffer[used++] = c;
    }
    buffer[used] = '\0';

    return buffer;
}
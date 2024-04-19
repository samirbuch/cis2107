//
// Created by Samir Buch on 4/18/24.
//

#include "str_utils.h"
#include <stdlib.h>

// Returns a new string consisting of all the characters of s1 and s2
// interleaved with each other.
// For example, if s1 is "Spongebob" and s2 is "Patrick",
// the function returns the string "SPpaotnrgiecbkob"
char *str_zip(const char *s1, const char *s2) {
    size_s s1Len = s_strlen(s1);
    size_s s2Len = s_strlen(s2);

    char *zipped = calloc(s1Len + s2Len, sizeof(char));

    int s1Iter = 0;
    int s2Iter = 0;
    for(int i = 0; i < s1Len + s2Len; i++) {
        if(i % 2 == 0)
            zipped[i] = s1[s1Iter++];
        else
            zipped[i] = s2[s2Iter++];
    }

    return zipped;
}
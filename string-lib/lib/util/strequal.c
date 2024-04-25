//
// Created by Samir Buch on 4/18/24.
//

#include "../str_utils.h"

int strequal(const char* s1, const char* s2) {
    size_s s1Len = s_strlen(s1);
    size_s s2Len = s_strlen(s2);

    if(s1Len != s2Len) return 0;

    for(int i = 0; i < s1Len; i++) {
        if(s1[i] != s2[i])
            return 0;
    }

    return 1;
}
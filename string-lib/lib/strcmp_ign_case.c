//
// Created by Samir Buch on 4/18/24.
//

#include "str_utils.h"

int strcmp_ign_case(const char *s1, const char *s2) {

    size_t s1Len = s_strlen(s1);
    size_t s2Len = s_strlen(s2);

    // Make s1 lowercase
    char s1Low[s1Len];
    for (int i = 0; i < s1Len; i++) {
        s1Low[i] = s_tolower(s1[i]);
    }

    char s2Low[s2Len];
    for (int i = 0; i < s2Len; i++) {
        s2Low[i] = s_tolower(s2[i]);
    }

    int diff = 0;
    for(int i = 0; i < s1Len; i++) {
        if(s1Low[i] == s2Low[i]) continue; // They're the same character

        // Once we hit the first not-same character, compare them.
        if(s1Low[i] > s2Low[i]) {
            diff = -1;
            break;
        } else if(s1Low[i] < s2Low[i]) {
            diff = 1;
            break;
        }
    }

    return diff;
}
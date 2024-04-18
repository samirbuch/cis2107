//
// Created by Samir Buch on 4/18/24.
//

#include "str_utils.h"

int find(char* h, char* n){
    size_s hLen = s_strlen(h);
    size_s nLen = s_strlen(n);

    // GUESS WHAT TIME IT IS???
    //
    // IT'S TIME FOR MY FAVORITE
    // ALGORITHM OF ALL TIME
    //
    // *drumroll*
    //
    // THE SLIDING WINDOW ALGORITHM 🎉

    int index = -1;

    for(int i = 0; i < hLen - nLen + 1; i++) {
        char window[hLen];
        // yes I had to reimplement strncpy for this.
        // really not the most difficult thing!
        s_strncpy(window, h + i, nLen);

        // strequal checks if two strings are equal.
        int equal = strequal(window, n);
        if(equal == 1) {
            index = i;
            break;
        }
    }

    return index;
}
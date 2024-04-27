//
// Created by Samir Buch on 4/18/24.
//

#include "str_utils.h"

int find(const char *h, const char *n){
    size_t hLen = s_strlen(h);
    size_t nLen = s_strlen(n);

    for(int i = 0; i < hLen - nLen + 1; i++) {
        char window[nLen];
        // yes I had to reimplement strncpy for this.
        // really not the most difficult thing!
        s_strncpy(window, h + i, nLen);

        // strequal checks if two strings are equal.
        int equal = strequal(window, n);
        if(equal == 1) {
            return i;
        }
    }

    return -1;
}
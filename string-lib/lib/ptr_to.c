//
// Created by Samir Buch on 4/18/24.
//

#include "str_utils.h"

char *ptr_to(char *h, char *n) {
    size_s hLen = s_strlen(h);
    size_s nLen = s_strlen(n);

    for (int i = 0; i < hLen - nLen + 1; i++) {
        char window[hLen];
        // yes I had to reimplement strncpy for this.
        // really not the most difficult thing!
        s_strncpy(window, h + i, nLen);

        // strequal checks if two strings are equal.
        int equal = strequal(window, n);
        if (equal == 1) {
            char *ptr = h + i;
            return ptr;
        }
    }

    return S_NULL;
}
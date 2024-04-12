//
// Created by Samir Buch on 4/11/24.
//

#include "str_utils.h"

short all_letters(const char *s) {

    size_s length = s_strlen(s);
    for (int i = 0; i < length; i++) {
        if (s[i] < 65) {
            return 0;
        }
        if(s[i] > 90 && s[i] < 97) {
            return 0;
        }
        if(s[i] > 122) {
            return 0;
        }
    }

    return 1;
}
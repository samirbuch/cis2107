//
// Created by Samir Buch on 4/18/24.
//

#include "str_utils.h"

int is_empty(const char *s) {
    size_s len = s_strlen(s);

    for(int i = 0; i < len; i++) {
        char c = s[i];
        if(c != ' ') return 0;
    }

    return 1;
}
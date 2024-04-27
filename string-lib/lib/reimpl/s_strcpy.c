//
// Created by Samir Buch on 4/18/24.
//

#include "reimpl.h"

void s_strcpy(char* dest, const char* src) {
    size_t src_len = s_strlen(src);

    for(int i = 0; i < src_len; i++) {
        dest[i] = src[i];
    }
}

void s_strncpy(char* dest, const char* src, size_t n) {
    for(int i = 0; i < n; i++){
        dest[i] = src[i];
    }
}
//
// Created by Samir Buch on 4/18/24.
//

#include "str_utils.h"

void s_strncpy(char* dest, const char* src, size_s n) {
    for(int i = 0; i < n; i++){
        dest[i] = src[i];
    }
}
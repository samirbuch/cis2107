//
// Created by Samir Buch on 4/13/24.
//

#include "str_utils.h"

size_t len_diff(const char* s1, const char* s2) {
    size_t str1_len = s_strlen(s1);
    size_t str2_len = s_strlen(s2);

    return s1 - s2;
}
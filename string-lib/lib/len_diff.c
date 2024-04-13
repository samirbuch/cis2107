//
// Created by Samir Buch on 4/13/24.
//

#include "str_utils.h"

size_s len_diff(const char* s1, const char* s2) {
    size_s str1_len = s_strlen(s1);
    size_s str2_len = s_strlen(s2);

    return s1 - s2;
}
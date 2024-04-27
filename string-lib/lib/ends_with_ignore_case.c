//
// Created by Samir Buch on 4/25/24.
//

#include "str_utils.h"

int ends_with_ignore_case(const char *s, const char *suffix) {
    size_t sLen = s_strlen(s);
    size_t suffixLen = s_strlen(suffix);

    char s_lowercase[sLen + 1];
    char suffix_lowercase[suffixLen + 1];

    for(int i = 0; i < sLen; i++) {
        s_lowercase[i] = s_tolower(s[i]);
    }
    s_lowercase[sLen + 1] = '\0';

    for(int i = 0; i < suffixLen; i++) {
        suffix_lowercase[i] = s_tolower(suffix[i]);
    }
    suffix_lowercase[suffixLen + 1] = '\0';

    int suffixCounter = 0;
    for(size_t i = sLen - suffixLen; i < sLen; i++) {
        if(s_lowercase[i] != suffix_lowercase[suffixCounter++])
            return 0;
    }

    return 1;
}
//
// Created by Samir Buch on 4/18/24.
//

#include "str_utils.h"

int is_upper(char c);

void capitalize(char *s) {
    size_s len = s_strlen(s);

    // Make the first character uppercase
    s[0] = toupper(s[0]);

    int shouldUppercaseNextLetter = 0;
    for(int i = 1; i < len; i++) {
        // If the current character is a space, mark the next character to be uppercased
        if(s[i] == ' ') {
            shouldUppercaseNextLetter = 1;
            continue;
        }

        if(shouldUppercaseNextLetter == 1) {
            s[i] = toupper(s[i]);
            shouldUppercaseNextLetter = 0;
        }
    }
}

int is_upper(char c) {
    return c >= 65 && c <= 90 ? 1 : 0;
}
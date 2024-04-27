//
// Created by Samir Buch on 4/18/24.
//

#include "str_utils.h"

void capitalize(char *s) {
    size_t len = s_strlen(s);

    // Make the first character uppercase
    s[0] = s_toupper(s[0]);

    int shouldUppercaseNextLetter = 0;
    for(int i = 1; i < len; i++) {
        // If the current character is a space, mark the next character to be uppercased
        if(s[i] == ' ') {
            shouldUppercaseNextLetter = 1;
            continue;
        }

        if(shouldUppercaseNextLetter == 1) {
            s[i] = s_toupper(s[i]);
            shouldUppercaseNextLetter = 0;
        }
    }
}

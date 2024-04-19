//
// Created by Samir Buch on 4/18/24.
//

int strequal(const char* s1, const char* s2) {
    int is_equal = 1;

    while(*(s1++) != '\0' && *(s2++) != '\0') {
        if(*s1 != *s2) {
            is_equal = 0;
            break;
        }
    }

    return is_equal;
}
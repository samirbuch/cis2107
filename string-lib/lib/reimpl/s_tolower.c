//
// Created by Samir Buch on 4/18/24.
//

#include "../str_utils.h"

char s_tolower(char c) {
    if(c >= 'A' && c <= 'Z') return (char) ((int) c + 32); // If it's uppercase, make it lowercase.
    else return c; // If it's not within the uppercase alphabet, pass it through.
}
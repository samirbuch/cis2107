//
// Created by Samir Buch on 4/11/24.
//

#include "str_utils.h"

int min(int a, int b) {
    return (a < b) ? a : b;
}

// Implementation of the Damerau–Levenshtein distance algorithm!
// THANK YOU, https://arc.net/l/quote/khevfpgf
int diff(const char *s1, const char *s2) {
    // Calculate lengths of the strings
    size_t s1Length = s_strlen(s1);
    size_t s2Length = s_strlen(s2);

    // Create the 2d array to store the data
    int d[s1Length + 1][s2Length + 1];

    // Init
    for (int i = 0; i <= s1Length; i++) {
        d[i][0] = i;
    }
    for (int j = 0; j <= s2Length; j++) {
        d[0][j] = j;
    }

    // Populate the 2d array
    for (int i = 1; i <= s1Length; i++) {
        for (int j = 1; j <= s2Length; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                d[i][j] = d[i - 1][j - 1];
            } else {
                d[i][j] = 1 +
                          min(d[i - 1][j], // deletion!
                              min(d[i][j - 1], // insertion!
                                  d[i - 1][j - 1])); // substitution!
            }
        }
    }

    // Return the distance!
    return d[s1Length][s2Length];
}
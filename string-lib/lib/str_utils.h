//
// Created by Samir Buch on 4/11/24.
//

#ifndef STRING_LIB_STR_UTILS_H
#define STRING_LIB_STR_UTILS_H

typedef unsigned int size_s;

/**
 * Return the length of a string, not including the null character at the end.
 * @param str String to check
 * @return Integer length of the string
 */
size_s s_strlen(const char* str);

/**
 * Return the length of a string up to and including n, not including the null character at the end.
 * @param str String to check
 * @param n Maximum length
 * @return Integer length of the string
 */
size_s s_strnlen(const char* str, size_s n);

/**
 * Returns 1 if all the characters in the string are either upper- or lower-case letters of the alphabet. 0 otherwise.
 * @param s String to test
 * @return 1 or 0
 */
short all_letters(const char *s);
// Fight for every byte!

/**
 * Returns the number of characters in s1 that are between b and t
 * @param s1 String to test
 * @param b Lower bound of characters to test for
 * @param t Upper bound of characters to test for
 * @return Number of characters in s1 between b and t
 */
size_s num_in_range(const char *s1, char b, char t);

/**
 * Returns the number of positions in which s1 and s2 differ, i.e. number of changes (substitutions, additions, subtractions) necessary to transform s1 into s2.
 * @param s1
 * @param s2
 * @return
 */
int diff(const char* s1, const char* s2);

/**
 * Shortens string s to the new length new_len. If the string is already shorter than new_len, no action is performed.
 * @param s String to shorten
 * @param new_len New length
 */
void shorten(char* s, int new_len);

#endif //STRING_LIB_STR_UTILS_H

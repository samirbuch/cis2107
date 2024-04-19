//
// Created by Samir Buch on 4/11/24.
//

#ifndef STRING_LIB_STR_UTILS_H
#define STRING_LIB_STR_UTILS_H

#define S_NULL ((void *)0)
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
 * Copy only n characters from the source string into the destination string
 * @param dest String to copy to
 * @param src String to copy from
 * @param n How many characters should be copied
 */
void s_strncpy(char* dest, const char* src, size_s n);

/**
 * Determines if two strings are exactly equal
 * @param s1 String one to check
 * @param s2 String two to check
 * @return 1 if equal, 0 if not
 */
int strequal(const char* s1, const char* s2);

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

/**
 * Returns the length of s1 minus the length of s2
 * @param s1 String 1
 * @param s2 String 2
 * @return Difference in length
 */
size_s len_diff(const char* s1, const char* s2);

/**
 * Removes whitespace characters from the beginning of s
 * @param s String to remove whitespace from
 */
void rm_left_space(char *s);

/**
 * Removes whitespace characters from the end of s
 * @param s String to remove whitespace from
 */
void rm_right_space(char *s);

/**
 * Removes whitespace characters from the beginning and end of s
 * @param s String to remove whitespace from
 */
void rm_space(char *s);

/**
 * Find the index of the first occurrence of n in the string h
 * @param h The string that gets searched
 * @param n String to find in h
 * @return Index to the first occurrence, -1 otherwise
 */
int find(const char *h, const char *n);

/**
 * Returns a pointer to the first occurrence of n in the string h
 * @param h The string that gets searched
 * @param n String to find in h
 * @return Pointer to first occurrence, NULL otherwise
 */
char *ptr_to(const char *h, const char *n);

/**
 * Checks to see if the string consists only of the null character or only whitespace.
 * @param s String to check
 * @return 1 if only whitespace, 0 otherwise.
 */
int is_empty(const char *s);

#endif //STRING_LIB_STR_UTILS_H

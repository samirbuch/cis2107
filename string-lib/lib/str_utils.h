//
// Created by Samir Buch on 4/11/24.
//

#ifndef STRING_LIB_STR_UTILS_H
#define STRING_LIB_STR_UTILS_H

#include "./reimpl/reimpl.h"

/**
 * Determines if two strings are exactly equal
 * @param s1 String one to check
 * @param s2 String two to check
 * @return 1 if equal, 0 if not
 */
int strequal(const char* s1, const char* s2);

/**
 * Converts character to its lowercase equivalent
 * @param c Character to convert
 * @return Lowercase character
 */
char tolower(char c);

/**
 * Converts character to its uppercase equivalent
 * @param c Character to convert
 * @return Uppercase character
 */
char toupper(char c);

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

/**
 * Returns a new string with s1 & s2 interleaved with each other
 * @param s1 String 1 to interleave
 * @param s2 String 2 to interleave
 * @return New string
 */
char *str_zip(const char *s1, const char *s2);

/**
 * Changes s such that the first letter of each word is uppercase and each additional letter is lowercase
 * @param s String to modify
 */
void capitalize(char *s);

/**
 * Compare s1 & s2, ignore case.
 * @param s1 String to compare against s2
 * @param s2 String to compare against s1
 * @return 1 if s1 would appear before s2 in a dictionary, -1 if s2 before s1, 0 if equal
 */
int strcmp_ign_case(const char *s1, const char *s2);

/**
 * Returns a copy of s with each instance of the given pattern replaced with the given replacement
 * The pattern and replacement MUST be the same length! Differing lengths are not implemented.
 * @param s String to copy
 * @param pattern Pattern to search for
 * @param replacement String to replace the patterns with
 * @return Pointer to a new string with the patterns replaced. S_NULL if it fails.
 */
char *replace(const char *s, const char *pattern, const char *replacement);

#endif //STRING_LIB_STR_UTILS_H

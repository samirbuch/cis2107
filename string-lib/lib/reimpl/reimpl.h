//
// Created by Samir Buch on 4/18/24.
//

#ifndef STRING_LIB_REIMPL_H
#define STRING_LIB_REIMPL_H

#define S_NULL ((void *)0)
typedef unsigned int size_s;

/**
 * Return the length of a string, not including the null character at the end.
 * @param str String to check
 * @return Integer length of the string
 */
size_s s_strlen(const char* str);

/**
 * Copies characters from the source string into the destination buffer
 * @param dest Destination buffer
 * @param src Source string
 */
void s_strcpy(char* dest, const char* src);

/**
 * Copies n characters from the source string into the destination buffer
 * @param dest Destination buffer
 * @param src Source string
 * @param n Maximum number of characters to copy
 */
void s_strncpy(char* dest, const char* src, size_s n);

/**
 * Converts character to its lowercase equivalent
 * @param c Character to convert
 * @return Lowercase character
 */
char s_tolower(char c);

/**
 * Converts character to its uppercase equivalent
 * @param c Character to convert
 * @return Uppercase character
 */
char s_toupper(char c);

#endif //STRING_LIB_REIMPL_H

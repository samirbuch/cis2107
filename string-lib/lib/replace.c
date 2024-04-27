//
// Created by Samir Buch on 4/24/24.
//

#include "str_utils.h"
#include <stdlib.h>

char *replace(const char *s, const char *pattern, const char *replacement) {
    size_t patternLen = s_strlen(pattern);
    size_t replacementLen = s_strlen(replacement);

    if (patternLen != replacementLen) {
        return S_NULL;
    }

    char *new_buffer = calloc(s_strlen(s) + 1, sizeof(char));
    s_strcpy(new_buffer, s); // Copy the string into the new buffer

    while (ptr_to(s, pattern) != S_NULL) {
        int found_index = find(new_buffer, pattern);
        for (size_t i = 0; i < s_strlen(pattern); i++) {
            new_buffer[i + found_index] = *(replacement++);
        }

        replacement -= replacementLen; // Rewind the replacement pointer
        s += found_index + patternLen; // Move the pointer forward, so we can search for the next occurrence
    }

    return new_buffer;
}

//char *replace(char *s, char *pattern, char *replacement) {
//
//    size_t sLen = s_strlen(s);
//    size_t patternLen = s_strlen(pattern);
//    size_t replacementLen = s_strlen(replacement);
//
//    size_t bufferLength = sLen;
//    char *new_buffer = calloc(bufferLength, sizeof(char));
//
//    s_strcpy(new_buffer, s);
//
//    char *p;
//
//    while((p = ptr_to(s, pattern)) != S_NULL) {
//        s = p; // Move the string s to the found pointer
//        size_t pLen = s_strlen(p);
//
//        // If the current buffer length minus the pattern length plus replacement length
//        // is greater than the current buffer length, we need to reallocate
//        if(bufferLength - patternLen + replacementLen > bufferLength) {
//            void* reallocated_buffer = realloc(new_buffer, bufferLength + replacementLen);
//            if(reallocated_buffer == NULL) return S_NULL; // fail silently i guess
//            new_buffer = reallocated_buffer; // set the new pointer
//            bufferLength += replacementLen; // set the new buffer size
//        }
//
//        // If the replacement string is larger than the pattern string, we need to move the
//        // buffer string forward by the difference between the pattern length and the replacement length.
//        // The above calculation should have taken care of ensuring the proper size is set.
//        // This logic will move the buffer forward.
//        if(replacementLen > patternLen) {
//            char *ptr_in_new_buffer = ptr_to(new_buffer, pattern);
//            ptr_in_new_buffer += replacementLen - patternLen;
//            size_t remainingLength = s_strlen(ptr_in_new_buffer);
//            for(size_t i = remainingLength; i > 0; i--) {
//
//            }
//        }
//
//        // Move the pointer to ahead of the pattern again, so we can match the next instance
//        s += patternLen;
//    }
//
//    return new_buffer;
//}

// this would have been so much easier with regex.
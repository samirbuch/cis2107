//
// Created by Samir Buch on 4/27/24.
//

#include "str_utils.h"

void rm_empties(char **words) {
   int nonEmptyIndex = 0;

   for(int i = 0; words[i] != S_NULL; i++) {
       if(*words[i] != '\0') {
           words[nonEmptyIndex++] = words[i];
       }
   }

   words[nonEmptyIndex] = S_NULL;
}
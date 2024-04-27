#include <stdio.h>
#include <stdlib.h>
#include "lib/str_utils.h"

int main() {
    char str[] = "HelloWorld";

    size_s length = s_strlen(str);

    printf("%s %u\n", str, length);

    int is_all_letters = all_letters(str);
    printf("is \"%s\" all letters? %d\n", str, is_all_letters);

    char abcStr[] = "ABC ABC DEF ABC";
    size_s num_range = num_in_range(abcStr, 'A', 'C');
    printf("%s contains %d characters between a and c\n", abcStr, num_range);

    char realString[] = "Rich Heir Estate Services";
    char fakeString[] = "Rich Hair State Service";
    size_s difference = diff(realString, fakeString);
    printf("Diff between: \n\t%s\n\t%s\n%d\n", realString, fakeString, difference);
    int comparison = strcmp_ign_case(realString, fakeString);
    printf("Comparison: %d\n", comparison);

    // Shorten the real string
    shorten(realString, 9);
    printf("Shortened string: %s\n", realString);

    printf("Length diff between s1 & s2: %u\n", len_diff(realString, fakeString));

    char strWithLeftSpaces[] = "        left space!";
    rm_left_space(strWithLeftSpaces);
    printf("\"%s\"\n", strWithLeftSpaces);

    char strWithRightSpaces[] = "right spaces!         ";
    rm_right_space(strWithRightSpaces);
    printf("\"%s\"\n", strWithRightSpaces);

    char soMuchSpace[] = "       so much space!       ";
    rm_space(soMuchSpace);
    printf("\"%s\"\n", soMuchSpace);

    char str1[] = "Prof. Ajaj is the greatest!";
    char str2[] = "Ajaj";

    int foundIndex = find(str1, str2);
    printf("Found %s index: %d\n", str2, foundIndex);

    char *foundPtr = ptr_to(str1, str2);
    printf("Found %s at pointer: %p (%c)\n", str2, foundPtr, *foundPtr);

    char notEmpty[] = "Not empty!";
    char empty[] = "";
    printf("Is \"%s\" empty? %d\n", notEmpty, is_empty(notEmpty));
    printf("Is \"%s\" empty? %d\n", empty, is_empty(empty));

    char spongebob[] = "Spongebob";
    char patrick[] = "Patrick";
    char *zipped = str_zip(spongebob, patrick);
    printf("Zipped: %s\n", zipped);
    free(zipped);

    // the quick brown dog...
    char sphinx[] = "sphinx of black quartz judge my vow";
    capitalize(sphinx);
    printf("Proper case-d: %s\n", sphinx);

    char replaceMe[] = "replace me with me";
    char patternSearch[] = "me";
    char replaceWith[] = "it";
    char* replacedString = replace(replaceMe, patternSearch, replaceWith);
    printf("Replacing instances of %s with %s in:\n%s:\n%s\n",
           patternSearch, replaceWith, replaceMe, replacedString);
    free(replacedString);

    char lastN[] = "abc def ghi jkl mno pqr";
    printf("Taking the last 5 characters of %s: ", lastN);
    take_last(lastN, 5);
    printf("%s\n", lastN);

    char duplicated[] = "ABABABABABA CDCDCDCDCD EFEFEFEFEF GGG HHH III";
    char *deduplicated = dedup(duplicated);
    printf("Deduplicated: %s\n", deduplicated);
    free(deduplicated);

    char *paddedString = pad("aaaaaaaaaaa", 5);
    printf("Padded string: \"%s\"\n", paddedString);
    free(paddedString);

    char suffixTestString[] = "I want to be done with this lab so bad";
    char suffix[] = "SO Bad";
    printf("Suffix test string ends with suffix? %d\n", ends_with_ignore_case(suffixTestString, suffix));

    char strToRepeat[] = "all right";
    char separator = ',';
    char *repeated = repeat(strToRepeat, 3, separator);
    printf("Repeated: \"%s\"\n", repeated);
    free(repeated);

    char *toConnect[] = { "hello", "professor", "ajaj!", "cool", "lab!" };
    char *connected = str_connect(toConnect, 5, '+');
    printf("Connected: \"%s\"\n", connected);
    free(connected);

    char *toConnect2[] = { "Washington", "Adams", "Jefferson" };
    char *connected2 = str_connect(toConnect2, 3, '+');
    printf("Connected: \"%s\"\n", connected2);

    return 0;
}

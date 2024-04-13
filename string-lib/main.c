#include <stdio.h>
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

    // Shorten the real string
    shorten(realString, 9);
    printf("Shortened string: %s\n", realString);

    return 0;
}
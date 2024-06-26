/*
 * Name:	XXX	XXXX 
 * Section:	XX 
 * Lab:  	CIS2107_Lab08_Manual 
 * Goal: 	To design and implement functions taking pointers as arguments 
			to process characters and strings.
 */


#include <stdio.h>
#include <memory.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//functions prototypes
void *upperLower(const char *s);

int convertStrToInt(const char *s1, const char *s2, const char *s3, const char *s4);

float convertStrToFloat(const char *s1, const char *s2, const char *s3, const char *s4);

void compareStr(const char *s1, const char *s2);

void comparePartialStr(const char *s1, const char *s2, int n);

void randomize(void);

void tokenizeTelNum(char *num);

void reverse(char *text);

int countSubstr(char *line, char *sub);

int countChar(char *line, char c);

int countWords(char *string);

void countAlpha(char *string);

void startsWithB(char *string[], int size);

void endsWithed(char *string[], int size);

int main() {

    //random generator
    srand(time(NULL));

    //test for upperLower
    const char test[] = "This iS A Test";
    upperLower(test);

    //test for convertStrToInt
    printf("\n\nThe sum of 4 strings is: %d", convertStrToInt("3", "4", "5", "6"));

    //test for convertStrToFloat
    printf("\n\nThe sum of 4 strings is: %.2f\n", convertStrToFloat("3.5", "4.5", "5.5", "6.5"));

    //test for compareStr
    compareStr("Test1", "Test2");

    //test for comparePartialStr
    comparePartialStr("Test1", "Test2", 4);

    //test for randomize
    randomize();

    //test for tokenize number
    char str[] = "(267) 436-6281";
    tokenizeTelNum(str);

    //test for reverse
    char line[] = "Hello world";
    reverse(line);

    //test for countSubstr
    char *line1 = "helloworldworld";
    char *substring = "world";
    printf("\n\nNumber of Substrings %s inside %s: %d\n", substring, line1, countSubstr(line1, substring));

    //test for countChar
    char w = 'w';
    printf("\nNumber of character %c inside %s: %d\n", w, line1, countChar(line1, w));

    //test for countAlpha
    char str1[] = "Hello it's me."; // https://open.spotify.com/track/3gHFKiDanj4d2rqgHlRFFc?si=e8aa16db285641f3
    countAlpha(str1);

    //test for countWords
    char countstring[] = "hello world!";
    printf("\n\nNumber of words in string is: %d\n", countWords(countstring));

    //test for startsWithB
    char *series[] = {"bored", "hello", "Brother", "manual", "bothered"};
    startsWithB(series, sizeof(series) / sizeof(series[0]));

    //test for endsWithed
    endsWithed(series, sizeof(series) / sizeof(series[0]));

}

// 1.(Displaying Strings in Uppercase and Lowercase) 
void *upperLower(const char *s) {
    size_t sLen = strlen(s);

    // convert to uppercase
    char *upper = calloc(sLen, sizeof(char));
    char *lower = calloc(sLen, sizeof(char));
    // hey why the fuck did I have to use calloc here instead of just a bunch of arrays?
    // it was spitting back some corrupted bullshit every time I tried to use
    // a standard array. wtf.
    // heap better ig. the virgin stack skill issue vs the chad heap

    for (int i = 0; i < strlen(s); i++) {
        upper[i] = (char) toupper(s[i]);
        lower[i] = (char) tolower(s[i]);
    }
    printf("%s\n", upper);
    printf("%s\n", lower);

    free(upper);
    free(lower);

    return NULL;
}

// 2.(Converting Strings to Integers for Calculations) 
int convertStrToInt(const char *s1, const char *s2, const char *s3, const char *s4) {
    // The only strings being passed in are a single character long, so we don't need to worry about
    // indexing into lengths beyond that. Just use the zeroth index. Nbd.

    // Minus 48 because, for example, "6" = ascii decimal value 54
    int s1Int = (int) s1[0] - 48;
    int s2Int = (int) s2[0] - 48;
    int s3Int = (int) s3[0] - 48;
    int s4Int = (int) s4[0] - 48;

    return s1Int + s2Int + s3Int + s4Int;
}

//3.(Converting Strings to Floating Point for Calculations) 
float convertStrToFloat(const char *s1, const char *s2, const char *s3, const char *s4) {
    // There's a better way to do this that utilizes strtok, but for the constant data set
    // of each string only being three characters "ones.tenths", I CBA. Just index.

    // Why 48? Re: convertStrToInt
    int s1Ones = (int) s1[0] - 48;
    double s1Tenths = ((int) s1[2] - 48) * 0.1;

    int s2Ones = (int) s2[0] - 48;
    double s2Tenths = ((int) s2[2] - 48) * 0.1;

    int s3Ones = (int) s3[0] - 48;
    double s3Tenths = ((int) s3[2] - 48) * 0.1;

    int s4Ones = (int) s4[0] - 48;
    double s4Tenths = ((int) s4[2] - 48) * 0.1;

    return (float) (s1Ones + s1Tenths + s2Ones + s2Tenths + s3Ones + s3Tenths + s4Ones + s4Tenths);
}

//4.(Comparing Strings) 
void compareStr(const char *s1, const char *s2) {
    int compared = strcmp(s1, s2);

    switch (compared) {
        case -1: {
            puts("s1 is less than s2");
            break;
        }
        case 0: {
            puts("s1 is equal to s2");
            break;
        }
        case 1: {
            puts("s1 is greater than s2");
            break;
        }
        default: {
            fprintf(stderr, "How did you get here\n");
            break;
        }
    }
}

//5.(Comparing Portions of Strings) 
void comparePartialStr(const char *s1, const char *s2, int n) {
    int compared = strncmp(s1, s2, n);

    switch (compared) {
        case -1: {
            puts("s1 is less than s2");
            break;
        }
        case 0: {
            puts("s1 is equal to s2");
            break;
        }
        case 1: {
            puts("s1 is greater than s2");
            break;
        }
        default: {
            fprintf(stderr, "How did you get here\n");
            break;
        }
    }
}

//6.(Random Sentences) 
void randomize(void) {
    char *articles[] = {"a", "one", "some", "any"}; // 4
    char *nouns[] = {"boy", "girl", "dog", "town", "car"}; // 5
    char *verbs[] = {"drove", "jumped", "ran", "walked", "skipped"}; // 5
    char *prepositions[] = {"to", "from", "over", "under", "on"}; // 5

    for (int i = 0; i < 20; i++) {
        char *buf = calloc(200, sizeof(char));

        strcat(buf, articles[rand() % 4]);
        strcat(buf, " ");
        strcat(buf, nouns[rand() % 5]);
        strcat(buf, " ");
        strcat(buf, verbs[rand() % 5]);
        strcat(buf, " ");
        strcat(buf, prepositions[rand() % 5]);
        strcat(buf, " ");
        strcat(buf, articles[rand() % 4]);
        strcat(buf, " ");
        strcat(buf, nouns[rand() % 5]);
        strcat(buf, ".");

        buf[0] = (char) toupper(buf[0]);

        // short story version
        printf("%s ", buf);

        free(buf);
    }
    puts("");
}

//7.(Tokenizing Telephone Numbers) 
void tokenizeTelNum(char *num) {
    char delimiters[] = "()-";

    // Area code
    char *token = strtok(num, delimiters);
    int areaCode = atoi(token);

    // First part of the phone number
    token = strtok(NULL, delimiters); // strtok is so weird
    int fPhoneNum = atoi(token);

    // Last part of the phone number
    token = strtok(NULL, delimiters);
    int lPhoneNum = atoi(token);

    printf("Area code: %d, Phone number: %d\n",
           areaCode, fPhoneNum * 10000 + lPhoneNum);
}

//8.(Displaying a Sentence with Its Words Reversed) 
void reverse(char *text) {
    char *token = strtok(text, " ");
    char *words[50];
    int tokenCount = 0;

    while (token != NULL) {
        words[tokenCount++] = token;
        token = strtok(NULL, " ");
    }

    printf("Reversed: ");
    for (int i = tokenCount - 1; i >= 0; i--) {
        printf("%s ", words[i]);
    }
    puts("");
}

//9.(Counting the Occurrences of a Substring) 
int countSubstr(char *line, char *sub) {
    int numSubstrings = 0;

    // Sliding window algorithm (cursed)
    size_t numWindows = strlen(line) - strlen(sub) + 1;
    for (int i = 0; i < numWindows; i++) {
        // Create a buffer to hold the current window's string
        char *buf = calloc(strlen(sub), sizeof(char));
        // Copy in the window's string (line + index)
        strncpy(buf, line + i, strlen(sub)); // only copy in strlen(sub) characters

        char *found = strstr(buf, sub);
        if (found != NULL) {
            numSubstrings++;
        }

        free(buf);
    }

    return numSubstrings;
}

//10.(Counting the Occurrences of a Character) 
int countChar(char *line, char c) {
    char *found = strchr(line, c);

    int occurrences = 0;
    while (found != NULL) {
        printf("%s\n", found);

        found = strchr(found + 1, c);
        occurrences++;
    }

    return occurrences;

}

//11.(Counting the Letters of the Alphabet in a String) 
void countAlpha(char *string) {
    // Create a "map" of letters with their associated frequencies
    int counts[26] = {0};

    for (int i = 0; i < strlen(string); i++) {
        // Get the current character (lowercase) at i
        char c = (char) tolower(string[i]);
        // If the character is less than a or greater than z ...
        if (c < 'a' || c > 'z') continue; // ... it's not alphabet.

        // Lowercase letters begin at ascii decimal 97
        int index = (int) c - 97;
        // Increment the index of this character in the "map" by one
        counts[index]++;
    }

    // Loop through all letters in the "map"
    for (int i = 0; i < 26; i++) {
        // Uppercase starts from ascii decimal 65, lowercase from 97
        // & print the frequency at that letter
        printf("%c,%c | %d\n", i + 65, i + 97, counts[i]);
    }

}

//12.(Counting the Number of Words in a String) 
int countWords(char *string) {
    char *token = strtok(string, " \n");

    int count = 0;
    while (token != NULL) {
        count++;
        token = strtok(NULL, " \n");
    }

    return count;
}

//13.(Strings Starting with "b") 
void startsWithB(char *string[], int size) {
    for (int i = 0; i < size; i++) {
        char *str = string[i];
        if (tolower(str[0]) == 'b') printf("%s ", str);
    }
    puts(" ");
}

//14.(Strings Ending with "ed") 
void endsWithed(char *string[], int size) {
    for(int i = 0; i < size; i++) {
        char *str = string[i];
        size_t length = strlen(str);

        int result = strcmp(str + length - 2, "ed");
        if(result == 0) printf("%s ", str);
    }
    puts("");
}
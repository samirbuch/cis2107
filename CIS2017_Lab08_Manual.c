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

int tokenizeTelNum(char *num);

void reverse(char *text);

int countSubstr(char *line, char *sub);

int countChar(char *line, char c);

int countWords(char *string);

void countAlpha(char *string);

void startsWithB(char *string[]);

void endsWithed(char *string[]);

int main() {

    //random generator
    srand(time(NULL));

    //test for upperLower
    const char test[] = "This iS A Test";
    upperLower(test);

    //test for convertStrToInt
    printf("\n\nThe sum of 4 strings is: %d", convertStrToInt("3", "4", "5", "6"));

    //test for convertStrToFloat
    printf("\n\nThe sum of 4 strings is: %.2f", convertStrToFloat("3.5", "4.5", "5.5", "6.5"));

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
    char str1[] = "Hello it's me.";
    countAlpha(str1);

    //test for countWords
    char countstring[] = "hello world!";
    printf("\n\nNumber of words in string is: %d\n", countWords(countstring));

    //test for startsWithB
    char *series[] = {"bored", "hello", "Brother", "manual", "bothered"};
    startsWithB(series);

    //test for endsWithed
    endsWithed(series);

}

// 1.(Displaying Strings in Uppercase and Lowercase) 
void *upperLower(const char *s) {
    size_t sLen = strlen(s);

    // convert to uppercase
    char *upper = calloc(sLen, sLen * sizeof(char));
    char *lower = calloc(sLen, sLen * sizeof(char));
    for (int i = 0; i < strlen(s); i++) {
        upper[i] = (char) toupper(s[i]);
        lower[i] = (char) tolower(s[i]);
    }
    printf("%s\n", upper);
    printf("%s\n", lower);

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

}

//5.(Comparing Portions of Strings) 
void comparePartialStr(const char *s1, const char *s2, int n) {

}

//6.(Random Sentences) 
void randomize(void) {


}

//7.(Tokenizing Telephone Numbers) 
int tokenizeTelNum(char *num) {


}

//8.(Displaying a Sentence with Its Words Reversed) 
void reverse(char *text) {


}

//9.(Counting the Occurrences of a Substring) 
int countSubstr(char *line, char *sub) {


}

//10.(Counting the Occurrences of a Character) 
int countChar(char *line, char c) {


}


//11.(Counting the Letters of the Alphabet in a String) 
void countAlpha(char *string) {


}

//12.(Counting the Number of Words in a String) 
int countWords(char *string) {


}

//13.(Strings Starting with "b") 
void startsWithB(char *string[]) {


}

//14.(Strings Ending with "ed") 
void endsWithed(char *string[]) {


}
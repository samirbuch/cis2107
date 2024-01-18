#include <stdio.h>

// Main function. Return 0 for successful exit.
int main() {
    char str[50];
    printf("Enter your name:\n> ");
    scanf("%s", &str);
    printf("Hello, %s!\n", str);
    return 0;
}

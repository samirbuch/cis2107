#include <stdio.h>

int main() {
    char str[50];
    printf("Enter your name:\n> ");
    scanf("%s", &str);
    printf("Hello, %s!\n", str);
    return 0;
}

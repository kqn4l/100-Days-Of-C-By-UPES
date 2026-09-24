// Q91: Remove all vowels from a string.

/*
Sample Test Cases:
Input 1:
education
Output 1:
dctn

*/

#include <stdio.h>
#include <ctype.h>

int isVowel(char ch) {
    ch = tolower(ch);
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

int main() {
    char str[1000];
    if (!fgets(str, sizeof(str), stdin)) return 0;

    for (int i = 0; str[i] != '\0' && str[i] != '\r' && str[i] != '\n'; i++) {
        if (!isVowel(str[i])) {
            putchar(str[i]);
        }
    }
    putchar('\n');
    return 0;
}

// Q90: Toggle case of each character in a string.

/*
Sample Test Cases:
Input 1:
Hello
Output 1:
hELLO

*/

#include <stdio.h>
#include <ctype.h>

int main() {
    char str[1000];
    if (!fgets(str, sizeof(str), stdin)) return 0;

    for (int i = 0; str[i] != '\0' && str[i] != '\r' && str[i] != '\n'; i++) {
        if (islower(str[i])) {
            putchar(toupper(str[i]));
        } else if (isupper(str[i])) {
            putchar(tolower(str[i]));
        } else {
            putchar(str[i]);
        }
    }
    putchar('\n');
    return 0;
}

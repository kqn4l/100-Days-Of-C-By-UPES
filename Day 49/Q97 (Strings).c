// Q97: Print the initials of a name.

/*
Sample Test Cases:
Input 1:
John Doe
Output 1:
J.D.

*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char str[1000];
    if (!fgets(str, sizeof(str), stdin)) return 0;
    str[strcspn(str, "\r\n")] = '\0';

    int inWord = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isspace(str[i])) {
            if (!inWord) {
                printf("%c.", toupper(str[i]));
                inWord = 1;
            }
        } else {
            inWord = 0;
        }
    }
    printf("\n");
    return 0;
}

// Q98: Print initials of a name with the surname displayed in full.

/*
Sample Test Cases:
Input 1:
John David Doe
Output 1:
J.D. Doe

*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char str[1000];
    if (!fgets(str, sizeof(str), stdin)) return 0;
    str[strcspn(str, "\r\n")] = '\0';

    char words[20][100];
    int count = 0;

    char *token = strtok(str, " ");
    while (token != NULL && count < 20) {
        strcpy(words[count++], token);
        token = strtok(NULL, " ");
    }

    if (count == 0) return 0;

    for (int i = 0; i < count - 1; i++) {
        printf("%c.", toupper(words[i][0]));
    }
    if (count > 1) {
        printf(" ");
    }
    printf("%s\n", words[count - 1]);

    return 0;
}

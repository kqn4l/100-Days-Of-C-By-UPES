// Q96: Reverse each word in a sentence without changing the word order.

/*
Sample Test Cases:
Input 1:
I love coding
Output 1:
I evol gnidoc

*/

#include <stdio.h>
#include <string.h>

void reverse(char *start, char *end) {
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int main() {
    char str[1000];
    if (!fgets(str, sizeof(str), stdin)) return 0;
    str[strcspn(str, "\r\n")] = '\0';

    char *wordStart = str;
    char *temp = str;

    while (*temp) {
        if (*temp == ' ') {
            reverse(wordStart, temp - 1);
            wordStart = temp + 1;
        }
        temp++;
    }
    reverse(wordStart, temp - 1);

    printf("%s\n", str);
    return 0;
}

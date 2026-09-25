// Q94: Find the longest word in a sentence.

/*
Sample Test Cases:
Input 1:
I love programming
Output 1:
programming

*/

#include <stdio.h>
#include <string.h>

int main() {
    char str[1000];
    if (!fgets(str, sizeof(str), stdin)) return 0;

    char longestWord[1000] = "";
    int maxLen = 0;

    char currentWord[1000] = "";
    int curLen = 0;

    for (int i = 0; str[i] != '\0' && str[i] != '\r' && str[i] != '\n'; i++) {
        if (str[i] != ' ') {
            currentWord[curLen++] = str[i];
            currentWord[curLen] = '\0';
        } else {
            if (curLen > maxLen) {
                maxLen = curLen;
                strcpy(longestWord, currentWord);
            }
            curLen = 0;
            currentWord[0] = '\0';
        }
    }
    if (curLen > maxLen) {
        maxLen = curLen;
        strcpy(longestWord, currentWord);
    }

    printf("%s\n", longestWord);
    return 0;
}

// Q114: Write a program to take a string s as input. The task is to find the length of the longest substring without repeating characters. Print the length as output.

/*
Sample Test Cases:
Input 1:
s = "abcabcbb"
Output 1:
3

Input 2:
s = "bbbbb"
Output 2:
1

Input 3:
s = "pwwkew"
Output 3:
3

*/

#include <stdio.h>
#include <string.h>

int main() {
    char buf[2048];
    if (!fgets(buf, sizeof(buf), stdin)) return 0;

    char str[1000] = "";
    char *q1 = strchr(buf, '"');
    if (q1) {
        char *q2 = strchr(q1 + 1, '"');
        if (q2) {
            *q2 = '\0';
            strcpy(str, q1 + 1);
        }
    }
    if (str[0] == '\0') {
        char *eq = strchr(buf, '=');
        if (eq) {
            strcpy(str, eq + 1);
        } else {
            strcpy(str, buf);
        }
    }
    str[strcspn(str, "\r\n")] = '\0';

    int lastIndex[256];
    for (int i = 0; i < 256; i++) lastIndex[i] = -1;

    int maxLen = 0, start = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        unsigned char ch = (unsigned char)str[i];
        if (lastIndex[ch] >= start) {
            start = lastIndex[ch] + 1;
        }
        lastIndex[ch] = i;
        int curLen = i - start + 1;
        if (curLen > maxLen) maxLen = curLen;
    }

    printf("%d\n", maxLen);
    return 0;
}

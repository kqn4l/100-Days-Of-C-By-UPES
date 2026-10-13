// Q115: Write a program to take two strings s and t as inputs (assume all characters are lowercase). The task is to determine if s and t are valid anagrams, meaning they contain the same characters with the same frequencies. Print "Anagram" if they are, otherwise "Not Anagram".

/*
Sample Test Cases:
Input 1:
s = "anagram", t = "nagaram"
Output 1:
Anagram

Input 2:
s = "rat", t = "car"
Output 2:
Not Anagram

*/

#include <stdio.h>
#include <string.h>

int main() {
    char buf[2048];
    if (!fgets(buf, sizeof(buf), stdin)) return 0;

    char s[500] = "", t[500] = "";
    char *q1 = strchr(buf, '"');
    if (q1) {
        char *q2 = strchr(q1 + 1, '"');
        if (q2) {
            *q2 = '\0';
            strcpy(s, q1 + 1);
            char *q3 = strchr(q2 + 1, '"');
            if (q3) {
                char *q4 = strchr(q3 + 1, '"');
                if (q4) {
                    *q4 = '\0';
                    strcpy(t, q3 + 1);
                }
            }
        }
    }

    if (s[0] == '\0') {
        sscanf(buf, "%s %s", s, t);
    }

    int count[26] = {0};
    int lenS = strlen(s), lenT = strlen(t);

    if (lenS != lenT) {
        printf("Not Anagram\n");
        return 0;
    }

    for (int i = 0; i < lenS; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') count[s[i] - 'a']++;
        if (t[i] >= 'a' && t[i] <= 'z') count[t[i] - 'a']--;
    }

    int isAnagram = 1;
    for (int i = 0; i < 26; i++) {
        if (count[i] != 0) {
            isAnagram = 0;
            break;
        }
    }

    if (isAnagram) {
        printf("Anagram\n");
    } else {
        printf("Not Anagram\n");
    }

    return 0;
}

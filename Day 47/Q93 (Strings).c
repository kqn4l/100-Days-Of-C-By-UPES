// Q93: Check if two strings are anagrams of each other.

/*
Sample Test Cases:
Input 1:
listen
silent
Output 1:
Anagrams

Input 2:
hello
world
Output 2:
Not anagrams

*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char s1[1000], s2[1000];
    if (!fgets(s1, sizeof(s1), stdin)) return 0;
    if (!fgets(s2, sizeof(s2), stdin)) return 0;

    int count[256] = {0};
    int len1 = 0, len2 = 0;

    for (int i = 0; s1[i] != '\0' && s1[i] != '\r' && s1[i] != '\n'; i++) {
        count[(unsigned char)tolower(s1[i])]++;
        len1++;
    }
    for (int i = 0; s2[i] != '\0' && s2[i] != '\r' && s2[i] != '\n'; i++) {
        count[(unsigned char)tolower(s2[i])]--;
        len2++;
    }

    int isAnagram = (len1 == len2);
    if (isAnagram) {
        for (int i = 0; i < 256; i++) {
            if (count[i] != 0) {
                isAnagram = 0;
                break;
            }
        }
    }

    if (isAnagram) {
        printf("Anagrams\n");
    } else {
        printf("Not anagrams\n");
    }
    return 0;
}

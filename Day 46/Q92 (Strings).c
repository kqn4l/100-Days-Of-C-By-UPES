// Q92: Find the first repeating lowercase alphabet in a string.

/*
Sample Test Cases:
Input 1:
stress
Output 1:
s

*/

#include <stdio.h>

int main() {
    char str[1000];
    if (!fgets(str, sizeof(str), stdin)) return 0;

    int freq[26] = {0};
    char firstRepeating = '\0';

    for (int i = 0; str[i] != '\0' && str[i] != '\r' && str[i] != '\n'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            freq[str[i] - 'a']++;
            if (freq[str[i] - 'a'] == 2 && firstRepeating == '\0') {
                firstRepeating = str[i];
            }
        }
    }

    if (firstRepeating != '\0') {
        printf("%c\n", firstRepeating);
    } else {
        printf("None\n");
    }
    return 0;
}

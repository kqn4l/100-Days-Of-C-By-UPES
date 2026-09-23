// Q89: Count frequency of a given character in a string.

/*
Sample Test Cases:
Input 1:
programming
g
Output 1:
2

*/

#include <stdio.h>

int main() {
    char str[1000];
    if (!fgets(str, sizeof(str), stdin)) return 0;

    char target;
    if (scanf(" %c", &target) != 1) return 0;

    int count = 0;
    for (int i = 0; str[i] != '\0' && str[i] != '\r' && str[i] != '\n'; i++) {
        if (str[i] == target) {
            count++;
        }
    }

    printf("%d\n", count);
    return 0;
}

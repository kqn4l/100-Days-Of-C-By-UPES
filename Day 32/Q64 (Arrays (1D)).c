// Q64: Find the digit that occurs the most times in an integer number.

/*
Sample Test Cases:
Input 1:
112233
Output 1:
1

Input 2:
887799
Output 2:
7

*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    long long num;
    if (scanf("%lld", &num) != 1) return 0;
    if (num < 0) num = -num;

    int freq[10] = {0};
    if (num == 0) {
        freq[0] = 1;
    } else {
        while (num > 0) {
            freq[num % 10]++;
            num /= 10;
        }
    }

    int maxCount = 0;
    int bestDigit = 0;
    for (int d = 0; d <= 9; d++) {
        if (freq[d] > maxCount) {
            maxCount = freq[d];
            bestDigit = d;
        }
    }

    printf("%d\n", bestDigit);
    return 0;
}

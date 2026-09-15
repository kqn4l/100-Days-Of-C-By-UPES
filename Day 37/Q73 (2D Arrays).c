// Q73: Find the sum of each row of a matrix and store it in an array.

/*
Sample Test Cases:
Input 1:
2 3
1 2 3
4 5 6
Output 1:
6 15

*/

#include <stdio.h>

int main() {
    int r, c;
    if (scanf("%d %d", &r, &c) != 2) return 0;
    int rowSum[r];
    for (int i = 0; i < r; i++) {
        rowSum[i] = 0;
        for (int j = 0; j < c; j++) {
            int val;
            scanf("%d", &val);
            rowSum[i] += val;
        }
    }

    for (int i = 0; i < r; i++) {
        printf("%d%c", rowSum[i], (i == r - 1) ? '\n' : ' ');
    }

    return 0;
}

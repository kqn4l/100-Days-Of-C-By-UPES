// Q79: Perform diagonal traversal of a matrix.

/*
Sample Test Cases:
Input 1:
3 3
1 2 3
4 5 6
7 8 9
Output 1:
1 2 4 7 5 3 6 8 9

*/

#include <stdio.h>

int main() {
    int r, c;
    if (scanf("%d %d", &r, &c) != 2) return 0;
    int mat[r][c];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    int total = r * c;
    int count = 0;
    for (int s = 0; s < r + c - 1; s++) {
        if (s % 2 == 0) {
            int row = (s < r) ? s : r - 1;
            int col = s - row;
            while (row >= 0 && col < c) {
                printf("%d%c", mat[row][col], (++count == total) ? '\n' : ' ');
                row--;
                col++;
            }
        } else {
            int col = (s < c) ? s : c - 1;
            int row = s - col;
            while (col >= 0 && row < r) {
                printf("%d%c", mat[row][col], (++count == total) ? '\n' : ' ');
                row++;
                col--;
            }
        }
    }

    return 0;
}

// Q63: Merge two arrays.

/*
Sample Test Cases:
Input 1:
3
1 2 3
2
4 5
Output 1:
1 2 3 4 5

*/

#include <stdio.h>

int main() {
    int n1, n2;
    if (scanf("%d", &n1) != 1) return 0;
    int a[n1];
    for (int i = 0; i < n1; i++) {
        scanf("%d", &a[i]);
    }
    if (scanf("%d", &n2) != 1) return 0;
    int b[n2];
    for (int i = 0; i < n2; i++) {
        scanf("%d", &b[i]);
    }

    int merged[n1 + n2];
    for (int i = 0; i < n1; i++) {
        merged[i] = a[i];
    }
    for (int i = 0; i < n2; i++) {
        merged[n1 + i] = b[i];
    }

    for (int i = 0; i < n1 + n2; i++) {
        printf("%d%c", merged[i], (i == n1 + n2 - 1) ? '\n' : ' ');
    }

    return 0;
}

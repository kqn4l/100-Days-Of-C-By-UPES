// Q66: Insert an element in a sorted array at the appropriate position.

/*
Sample Test Cases:
Input 1:
5
1 2 4 5 6
3
Output 1:
1 2 3 4 5 6

*/

#include <stdio.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int arr[n + 1];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int val;
    if (scanf("%d", &val) != 1) return 0;

    int pos = n;
    for (int i = 0; i < n; i++) {
        if (arr[i] > val) {
            pos = i;
            break;
        }
    }

    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = val;

    for (int i = 0; i <= n; i++) {
        printf("%d%c", arr[i], (i == n) ? '\n' : ' ');
    }

    return 0;
}

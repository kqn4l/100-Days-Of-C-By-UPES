// Q112: Write a program to take an integer array arr as input. The task is to find the maximum sum of any contiguous subarray using Kadane's algorithm. Print the maximum sum as output. If all elements are negative, print the largest (least negative) element.

/*
Sample Test Cases:
Input 1:
arr[] = [2, 3, -8, 7, -1, 2, 3]
Output 1:
11

Input 2:
arr[] = [-2, -4]
Output 2:
-2

Input 3:
arr[] = [5, 4, 1, 7, 8]
Output 3:
25

*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    char buf[2048];
    if (!fgets(buf, sizeof(buf), stdin)) return 0;

    int arr[500];
    int count = 0;
    char *p = buf;
    while (*p) {
        if ((*p >= '0' && *p <= '9') || (*p == '-' && p[1] >= '0' && p[1] <= '9')) {
            arr[count++] = (int)strtol(p, &p, 10);
        } else {
            p++;
        }
    }

    if (count == 0) return 0;

    long long maxSoFar = arr[0];
    long long currMax = arr[0];

    for (int i = 1; i < count; i++) {
        currMax = (arr[i] > currMax + arr[i]) ? arr[i] : currMax + arr[i];
        if (currMax > maxSoFar) maxSoFar = currMax;
    }

    printf("%lld\n", maxSoFar);
    return 0;
}

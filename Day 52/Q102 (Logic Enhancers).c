// Q102: Write a Program to take a sorted array arr[] and an integer x as input, find the index (0-based) of the smallest element in arr[] that is greater than or equal to x and print it. This element is called the ceil of x. If such an element does not exist, print -1. Note: In case of multiple occurrences of ceil of x, return the index of the first occurrence.

/*
Sample Test Cases:
Input 1:
arr = [1, 2, 8, 10, 11, 12, 19], x = 5
Output 1:
2

Input 2:
arr = [1, 2, 8, 10, 11, 12, 19], x = 20
Output 2:
-1

Input 3:
arr = [1, 1, 2, 8, 10, 11, 12, 19], x = 0
Output 3:
0

Input 4:
arr = [1, 1, 2, 8, 10, 11, 12, 19], x = 2
Output 4:
2

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char buf[2048];
    if (!fgets(buf, sizeof(buf), stdin)) return 0;
    char extra[256];
    if (fgets(extra, sizeof(extra), stdin)) {
        strcat(buf, " ");
        strcat(buf, extra);
    }

    int arr[500];
    int count = 0;
    int x = 0;
    int hasX = 0;

    char *xPtr = strstr(buf, "x =");
    if (!xPtr) xPtr = strstr(buf, "x=");
    if (xPtr) {
        char *eq = strchr(xPtr, '=');
        if (eq) x = atoi(eq + 1);
        hasX = 1;
        *xPtr = '\0';
    }

    char *p = buf;
    while (*p) {
        if ((*p >= '0' && *p <= '9') || (*p == '-' && p[1] >= '0' && p[1] <= '9')) {
            arr[count++] = (int)strtol(p, &p, 10);
        } else {
            p++;
        }
    }

    if (!hasX && count > 0) {
        x = arr[count - 1];
        count--;
    }

    int ceilIdx = -1;
    for (int i = 0; i < count; i++) {
        if (arr[i] >= x) {
            ceilIdx = i;
            break;
        }
    }

    printf("%d\n", ceilIdx);
    return 0;
}

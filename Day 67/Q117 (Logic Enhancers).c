// Q117: Write a program to take two sorted arrays of size m and n as input. Merge both the arrays such that the merged array is also sorted. Print the merged array.

/*
Sample Test Cases:
Input 1:
nums1 = [2,7,11,15] nums2 = [4,8,10]
Output 1:
2 4 7 8 10 11 15

Input 2:
nums1 = [1,2,7] nums2 = [9,10,17]
Output 2:
1 2 7 9 10 17

Input 3:
nums1 = [-10,-2,7] nums2 = [-3, -1, 7]
Output 3:
-10 -3 -2 -1 7 7

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    char buf[2048];
    if (!fgets(buf, sizeof(buf), stdin)) return 0;
    char extra[1024];
    if (fgets(extra, sizeof(extra), stdin)) {
        strcat(buf, " ");
        strcat(buf, extra);
    }

    int all[1000];
    int count = 0;
    char *p = buf;
    while (*p) {
        if ((*p >= '0' && *p <= '9') || (*p == '-' && p[1] >= '0' && p[1] <= '9')) {
            all[count++] = (int)strtol(p, &p, 10);
        } else {
            p++;
        }
    }

    if (count == 0) return 0;

    qsort(all, count, sizeof(int), compare);

    for (int i = 0; i < count; i++) {
        printf("%d%s", all[i], (i == count - 1) ? "\n" : " ");
    }

    return 0;
}

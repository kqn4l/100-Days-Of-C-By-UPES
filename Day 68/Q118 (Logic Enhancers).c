// Q118: Write a program to take an input array of size n. The array should contain all the integers between 0 to n except for one. Print that missing number

/*
Sample Test Cases:
Input 1:
nums1 = [0,3,2,4]
Output 1:
1

Input 2:
nums1 = [1,2,3]
Output 2:
0

Input 3:
nums1 = [0,4,3,1,5]
Output 3:
2

*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    char buf[2048];
    if (!fgets(buf, sizeof(buf), stdin)) return 0;

    int nums[500];
    int count = 0;
    char *p = buf;
    while (*p) {
        if ((*p >= '0' && *p <= '9') || (*p == '-' && p[1] >= '0' && p[1] <= '9')) {
            nums[count++] = (int)strtol(p, &p, 10);
        } else {
            p++;
        }
    }

    int n = count;
    long long totalExpected = (long long)n * (n + 1) / 2;
    long long actualSum = 0;
    for (int i = 0; i < count; i++) {
        actualSum += nums[i];
    }

    printf("%lld\n", totalExpected - actualSum);
    return 0;
}

// Q119: Write a program to take an integer array as input. Only one element will be repeated. Print the repeated element. Try to find the result in one single iteration.

/*
Sample Test Cases:
Input 1:
nums1 = [1,3,3,4]
Output 1:
3

Input 2:
nums1 = [1,2,2]
Output 2:
2

Input 3:
nums1 = [0,4,1,1,5]
Output 3:
1

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

    int seen[10000] = {0};
    int repeated = -1;

    for (int i = 0; i < count; i++) {
        int val = nums[i];
        if (val >= 0 && val < 10000) {
            if (seen[val]) {
                repeated = val;
                break;
            }
            seen[val] = 1;
        }
    }

    printf("%d\n", repeated);
    return 0;
}

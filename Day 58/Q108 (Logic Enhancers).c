// Q108: Write a Program to take an integer array nums. Print an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i]. The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

/*
Sample Test Cases:
Input 1:
nums = [1,2,3,4]
Output 1:
[24,12,8,6]

Input 2:
nums = [-1,1,0,-3,3]
Output 2:
[0,0,9,0,0]

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

    if (count == 0) return 0;

    int answer[500];
    for (int i = 0; i < count; i++) {
        long long prod = 1;
        for (int j = 0; j < count; j++) {
            if (i != j) {
                prod *= nums[j];
            }
        }
        answer[i] = (int)prod;
    }

    printf("[");
    for (int i = 0; i < count; i++) {
        printf("%d%s", answer[i], (i == count - 1) ? "" : ",");
    }
    printf("]\n");

    return 0;
}

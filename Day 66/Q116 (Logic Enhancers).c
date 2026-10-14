// Q116: Write a program to take an integer array nums which contains only positive integers, and an integer target as inputs. The goal is to find two distinct indices i and j in the array such that nums[i] + nums[j] equals the target. Assume exactly one solution exists and return the indices in any order. Print the two indices separated by a space as output. If no solution exists, print "-1 -1".

/*
Sample Test Cases:
Input 1:
nums = [2,7,11,15], target = 9
Output 1:
0 1

Input 2:
nums = [3,2,4], target = 6
Output 2:
1 2

Input 3:
nums = [3,3], target = 6
Output 3:
0 1

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

    int nums[500];
    int count = 0;
    int target = 0;
    int hasTarget = 0;

    char *tPtr = strstr(buf, "target");
    if (tPtr) {
        char *eq = strchr(tPtr, '=');
        if (eq) target = atoi(eq + 1);
        hasTarget = 1;
        *tPtr = '\0';
    }

    char *p = buf;
    while (*p) {
        if ((*p >= '0' && *p <= '9') || (*p == '-' && p[1] >= '0' && p[1] <= '9')) {
            nums[count++] = (int)strtol(p, &p, 10);
        } else {
            p++;
        }
    }

    if (!hasTarget && count > 0) {
        target = nums[count - 1];
        count--;
    }

    int foundI = -1, foundJ = -1;
    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            if (nums[i] + nums[j] == target) {
                foundI = i;
                foundJ = j;
                break;
            }
        }
        if (foundI != -1) break;
    }

    if (foundI != -1) {
        printf("%d %d\n", foundI, foundJ);
    } else {
        printf("-1 -1\n");
    }

    return 0;
}

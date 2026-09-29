// Q101: Write a Program to take a sorted array(say nums[]) and an integer (say target) as inputs. The elements in the sorted array might be repeated. You need to print the first and last occurrence of the target and print the index of first and last occurrence. Print -1, -1 if the target is not present.

/*
Sample Test Cases:
Input 1:
nums = [5,7,7,8,8,10], target = 8
Output 1:
3,4

Input 2:
nums = [5,7,7,8,8,10], target = 6
Output 2:
-1,-1

Input 3:
nums = [5,7,7,8,8,10], target = 10
Output 3:
5,5

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char buf[2048];
    if (!fgets(buf, sizeof(buf), stdin)) return 0;
    // Check if more input follows
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

    int first = -1, last = -1;
    for (int i = 0; i < count; i++) {
        if (nums[i] == target) {
            if (first == -1) first = i;
            last = i;
        }
    }

    printf("%d,%d\n", first, last);
    return 0;
}

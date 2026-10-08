// Q110: Write a program to take an integer array arr and an integer k as inputs. The task is to find the maximum element in each subarray of size k moving from left to right. Print the maximum elements for each window separated by spaces as output.

/*
Sample Test Cases:
Input 1:
arr[1, 2, 3, 1, 4, 5, 2, 3, 6] = , k = 3
Output 1:
3 3 4 5 5 5 6

Input 2:
arr[5, 1, 3, 4, 2] = , k = 1
Output 2:
5 1 3 4 2

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
    int k = 0;
    int hasK = 0;

    char *kPtr = strstr(buf, "k =");
    if (!kPtr) kPtr = strstr(buf, "k=");
    if (kPtr) {
        char *eq = strchr(kPtr, '=');
        if (eq) k = atoi(eq + 1);
        hasK = 1;
        *kPtr = '\0';
    }

    char *p = buf;
    while (*p) {
        if ((*p >= '0' && *p <= '9') || (*p == '-' && p[1] >= '0' && p[1] <= '9')) {
            arr[count++] = (int)strtol(p, &p, 10);
        } else {
            p++;
        }
    }

    if (!hasK && count > 0) {
        k = arr[count - 1];
        count--;
    }

    if (count < k || k <= 0) return 0;

    for (int i = 0; i <= count - k; i++) {
        int maxVal = arr[i];
        for (int j = i + 1; j < i + k; j++) {
            if (arr[j] > maxVal) maxVal = arr[j];
        }
        printf("%d%s", maxVal, (i == count - k) ? "\n" : " ");
    }

    return 0;
}

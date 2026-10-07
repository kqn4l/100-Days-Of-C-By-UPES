// Q109: Write a program to take an integer array arr and an integer k as inputs. Print the maximum sum of all the subarrays of size k.

/*
Sample Test Cases:
Input 1:
arr[100, 200, 300, 400] = , k = 2
Output 1:
700

Input 2:
arr[1, 4, 2, 10, 23, 3, 1, 0, 20] = , k = 4
Output 2:
39

Input 3:
arr[100, 200, 300, 400] = , k = 1
Output 3:
400

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

    long long curSum = 0;
    for (int i = 0; i < k; i++) curSum += arr[i];

    long long maxSum = curSum;
    for (int i = k; i < count; i++) {
        curSum += arr[i] - arr[i - k];
        if (curSum > maxSum) maxSum = curSum;
    }

    printf("%lld\n", maxSum);
    return 0;
}

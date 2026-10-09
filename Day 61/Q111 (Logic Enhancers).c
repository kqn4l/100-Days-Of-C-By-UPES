// Q111: Write a program to take an integer array arr and an integer k as inputs. The task is to find the first negative integer in each subarray of size k moving from left to right. If no negative exists in a window, print "0" for that window. Print the results separated by spaces as output.

/*
Sample Test Cases:
Input 1:
arr[] = [-8, 2, 3, -6, 10], k = 2
Output 1:
-8 0 -6 -6

Input 2:
arr[] = [12, -1, -7, 8, -15, 30, 16, 28], k = 3
Output 2:
-1 -1 -7 -15 -15 0

Input 3:
arr[] = [12, 1, 3, 5], k = 3
Output 3:
0 0

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
        int firstNeg = 0;
        for (int j = i; j < i + k; j++) {
            if (arr[j] < 0) {
                firstNeg = arr[j];
                break;
            }
        }
        printf("%d%s", firstNeg, (i == count - k) ? "\n" : " ");
    }

    return 0;
}

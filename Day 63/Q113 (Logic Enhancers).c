// Q113: Write a program to take an integer array arr and an integer k as inputs. The task is to find the kth smallest element in the array. Print the kth smallest element as output.

/*
Sample Test Cases:
Input 1:
arr[] = [10, 5, 4, 3, 48, 6, 2, 33, 53, 10], k = 4
Output 1:
5

Input 2:
arr[] = [7, 10, 4, 3, 20, 15], k = 3
Output 2:
7

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

    if (k <= 0 || k > count) return 0;

    qsort(arr, count, sizeof(int), compare);

    printf("%d\n", arr[k - 1]);
    return 0;
}

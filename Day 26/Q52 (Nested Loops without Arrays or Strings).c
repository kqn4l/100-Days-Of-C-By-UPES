// Q52: Write a program to print the following pattern:

// *

// *
// *
// *

// *
// *
// *
// *
// *

// *
// *
// *

// *



/*
Sample Test Cases:
Input 1:

Output 1:
Pattern with stars spaced irregularly as shown.

*/

#include <stdio.h>

int main() {
    int n = 5;

    for (int i = 1; i <= n; i++) {

        int stars;

        if (i <= 3)
            stars = 2 * i - 1;
        else
            stars = 2 * (n - i) + 1;

        for (int j = 1; j <= stars; j++) {
            printf("* ");
            printf("\n");
        }

        printf("\n");
    }

    return 0;
}
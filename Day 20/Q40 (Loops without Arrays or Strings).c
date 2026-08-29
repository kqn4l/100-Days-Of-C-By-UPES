// Q40: Write a program to find the 1’s complement of a binary number and print it.

/*
Sample Test Cases:
Input 1:
1010
Output 1:
0101

Input 2:
1111
Output 2:
0000

*/


#include <stdio.h>

int main() {
    int n;
    int complement = 0;
    int power = 1;
    int digit;
    printf("Enter a binary number: ");
    scanf("%d", &n);

    while (n != 0) {
        digit = n % 10;
        if (digit == 0) {
            complement += 1 * power;
        }
        n /= 10;
        power *= 10;
    }

    printf("1's complement: %d\n", complement);
    return 0;
}
// Q29: Write a program to calculate the factorial of a number.

/*
Sample Test Cases:
Input 1:
5
Output 1:
120

Input 2:
3
Output 2:
6

*/

#include <stdio.h>
int main() {
    int n;
    int factorial = 1;
    int num = 1;
    
    printf("Enter a number: ");
    scanf("%d", &n);
    
    while (num <= n) {
        factorial *= num;
        num++;
    }
    
    printf("Factorial of %d is: %d\n", n, factorial);
    
    return 0;
}
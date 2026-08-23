// Q27: Write a program to print the sum of the first n odd numbers.

/*
Sample Test Cases:
Input 1:
3
Output 1:
9

Input 2:
5
Output 2:
25

*/

#include <stdio.h>
int main() {
    int n;
    int sum = 0;
    int count = 0;
    int num = 1;
    
    printf("Enter the number of odd numbers to sum: ");
    scanf("%d", &n);
    
    while (count < n) {
        if (num % 2 != 0) {
            sum += num;
            count++;
        }
        num++;
    }
    
    printf("Sum of the first %d odd numbers is: %d\n", n, sum);
    
    return 0;
}
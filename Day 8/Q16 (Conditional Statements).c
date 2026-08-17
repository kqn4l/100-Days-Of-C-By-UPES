// Q16: Write a program to input three numbers and find the largest among them using if–else.

/*
Sample Test Cases:
Input 1:
3 7 5
Output 1:
Largest is 7

Input 2:
-1 -5 0
Output 2:
Largest is 0

*/


#include <stdio.h>

int main() {
    int a;
    int b;
    int c;
    int largest;

    printf("Enter 1st number: ");
    scanf("%d", &a);;

    printf("Enter 2nd number: ");
    scanf("%d", &b);
    
    printf("Enter 3rd number: ");
    scanf("%d", &c);
    

    if (a >= b && a >= c) {
        largest = a;
    } else if (b >= a && b >= c) {
        largest = b;
    } else {
        largest = c;
    }

    printf("Largest is %d", largest);
    return 0;
}
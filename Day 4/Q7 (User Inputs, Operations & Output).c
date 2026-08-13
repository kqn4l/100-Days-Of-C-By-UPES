// Q7: Write a program to swap two numbers without using a third variable.

/*
Sample Test Cases:
Input 1:
10 20
Output 1:
After swap: 20 10

Input 2:
7 14
Output 2:
After swap: 14 7

*/


#include <stdio.h>
int main(){
    int a;
    int b;

    printf("Enter number 1: ");
    scanf("%d",&a);
    printf("Enter number 2: ");
    scanf("%d",&b);

    printf("Numbers Before swap: %d %d\n",a,b);

    a = a + b;
    b = a - b;
    a = a - b;

    printf("Numbers After swap: %d %d",a,b);
}
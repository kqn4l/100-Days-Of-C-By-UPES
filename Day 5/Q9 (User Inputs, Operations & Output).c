// Q9: Write a program to calculate simple and compound interest for given principal, rate, and time.

/*
Sample Test Cases:
Input 1:
1000 5 2
Output 1:
Simple Interest=100, Compound Interest=102.5

Input 2:
5000 7 3
Output 2:
Simple Interest=1050, Compound Interest=1125.76

*/

#include <stdio.h>

int main() {
    float principal;
    float rate; 
    float time;
    float simple_interest;
    float compound_interest;
    float amount = 1;


    printf("Enter Principal: ");
    scanf("%f", &principal);
    printf("Enter Rate: ");
    scanf("%f", &rate);
    printf("Enter Time: ");
    scanf("%f", &time);

    simple_interest = (principal * rate * time) / 100;

    for (int i = 1; i <= time; i++) {
        amount = amount * (1 + rate / 100);
    }

    compound_interest = principal * amount - principal;

    printf("Simple Interest=%.2f, Compound Interest=%.2f\n", simple_interest, compound_interest);

    return 0;
}
// Q5: Write a program to convert temperature from Celsius to Fahrenheit.

/*
Sample Test Cases:
Input 1:
0
Output 1:
Fahrenheit=32

Input 2:
100
Output 2:
Fahrenheit=212

*/

#include <stdio.h>
int main() {
    float celsius;
    float fahrenheit;

    printf("Enter temoprature in Celsius: ");
    scanf("%f",&celsius);

    fahrenheit = (celsius * 9/5)+32;

    printf("%.2f Celsius in Fahrenheit is %.2f", celsius, fahrenheit);
}
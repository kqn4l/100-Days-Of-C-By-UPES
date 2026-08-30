// Q41: Write a program to swap the first and last digit of a number.

/*
Sample Test Cases:
Input 1:
1234
Output 1:
4231

Input 2:
1001
Output 2:
1001
*/

#include <stdio.h>

int main() {
    int num;
    int first_digit;
    int last_digit;
    int num_digits;
    int temp_num;
    int divisor;
    int middle;
    int swapped_num;

    printf("Enter a number: ");
    scanf("%d", &num);

    // Find last digit
    last_digit = num % 10;

    // Find number of digits
    num_digits = 0;
    temp_num = num;

    while (temp_num > 0) {
        temp_num /= 10;
        num_digits++;
    }

    // Find first digit
    first_digit = num;
    while (first_digit >= 10) {
        first_digit /= 10;
    }

    if (num_digits > 1) {

        // Find place value of first digit
        divisor = 1;

        for (int i = 1; i < num_digits; i++) {
            divisor *= 10;
        }

        // Remove first and last digits
        middle = (num % divisor) / 10;

        // Swap first and last digits
        swapped_num = last_digit * divisor + middle * 10 + first_digit;

    } else {
        swapped_num = num;
    }

    printf("The number with the first and last digits swapped is: %d\n", swapped_num);

    return 0;
}
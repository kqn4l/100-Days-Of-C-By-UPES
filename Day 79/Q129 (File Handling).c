// Q129: A file numbers.txt contains a list of integers separated by spaces. Read all integers, compute their sum and average, and print both.

/*
Sample Test Cases:
Input 1:
File: numbers.txt (Content: 10 20 30 40 50)
Output 1:
Sum = 150 
 Average = 30.00

*/

#include <stdio.h>

int main() {
    FILE *fp = fopen("numbers.txt", "r");
    if (!fp) {
        fp = fopen("numbers.txt", "w");
        if (fp) {
            fprintf(fp, "10 20 30 40 50\n");
            fclose(fp);
            fp = fopen("numbers.txt", "r");
        }
    }

    if (!fp) {
        printf("Error opening numbers.txt\n");
        return 0;
    }

    long long sum = 0;
    int count = 0;
    int num;
    while (fscanf(fp, "%d", &num) == 1) {
        sum += num;
        count++;
    }
    fclose(fp);

    double avg = (count > 0) ? (double)sum / count : 0.0;
    printf("Sum = %lld \n Average = %.2f\n", sum, avg);
    return 0;
}

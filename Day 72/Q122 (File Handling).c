// Q122: Write a C program that opens an existing file (e.g., info.txt) and reads its contents using fgets(). The program should print all the lines to the console until EOF (end of file) is reached.

/*
Sample Test Cases:
Input 1:
File: info.txt (Content: Name: Rahul\nAge: 23)
Output 1:
Name: Rahul 
 Age: 23

*/

#include <stdio.h>

int main() {
    FILE *fp = fopen("info.txt", "r");
    if (fp == NULL) {
        // Create sample file if missing for standalone testing
        fp = fopen("info.txt", "w");
        if (fp) {
            fprintf(fp, "Name: Rahul\nAge: 23\n");
            fclose(fp);
            fp = fopen("info.txt", "r");
        }
    }

    if (fp != NULL) {
        char line[256];
        while (fgets(line, sizeof(line), fp)) {
            printf("%s", line);
        }
        fclose(fp);
    } else {
        printf("Error: Could not open file.\n");
    }

    return 0;
}

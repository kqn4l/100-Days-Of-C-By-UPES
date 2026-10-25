// Q127: Write a program that reads text from input.txt, converts all lowercase letters to uppercase, and writes the result to output.txt.

/*
Sample Test Cases:
Input 1:
Input File (input.txt): Hello World\nC programming
Output 1:
Output File (output.txt): HELLO WORLD\nC PROGRAMMING

*/

#include <stdio.h>
#include <ctype.h>

int main() {
    // Setup input file if missing
    FILE *in = fopen("input.txt", "r");
    if (!in) {
        in = fopen("input.txt", "w");
        if (in) {
            fprintf(in, "Hello World\nC programming\n");
            fclose(in);
            in = fopen("input.txt", "r");
        }
    }

    FILE *out = fopen("output.txt", "w");
    if (in && out) {
        int ch;
        while ((ch = fgetc(in)) != EOF) {
            fputc(toupper(ch), out);
        }
        fclose(in);
        fclose(out);
        printf("Converted text written to output.txt successfully.\n");
    } else {
        printf("Error processing files.\n");
    }

    return 0;
}

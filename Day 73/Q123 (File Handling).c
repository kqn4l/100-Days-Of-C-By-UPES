// Q123: Read a text file and count the total number of characters, words, and lines. A word is defined as a sequence of non-space characters separated by spaces or newlines.

/*
Sample Test Cases:
Input 1:
File: sample.txt (Content: Hello world\nThis is C programming)
Output 1:
Characters: 31 
 Words: 5 
 Lines: 2

*/

#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *fp = fopen("sample.txt", "r");
    if (fp == NULL) {
        fp = fopen("sample.txt", "w");
        if (fp) {
            fprintf(fp, "Hello world\nThis is C programming\n");
            fclose(fp);
            fp = fopen("sample.txt", "r");
        }
    }

    if (fp == NULL) {
        printf("Error opening file.\n");
        return 0;
    }

    int chars = 0, words = 0, lines = 0;
    int inWord = 0;
    int ch;

    while ((ch = fgetc(fp)) != EOF) {
        if (ch != '\r') chars++;
        if (ch == '\n') lines++;
        if (isspace(ch)) {
            inWord = 0;
        } else if (!inWord) {
            inWord = 1;
            words++;
        }
    }
    if (chars > 0 && lines == 0) lines = 1;
    fclose(fp);

    printf("Characters: %d \n Words: %d \n Lines: %d\n", chars, words, lines);
    return 0;
}

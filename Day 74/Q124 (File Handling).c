// Q124: Take two filenames from the user - a source file and a destination file. Copy all the content from the source file to the destination file using fgetc() and fputc().

/*
Sample Test Cases:
Input 1:
Source File: source.txt (Content: Learning C File Handling)
Output 1:
File copied successfully to destination.txt

*/

#include <stdio.h>

int main() {
    char src[100] = "source.txt";
    char dest[100] = "destination.txt";

    // Setup source if not present
    FILE *check = fopen(src, "r");
    if (!check) {
        check = fopen(src, "w");
        if (check) {
            fputs("Learning C File Handling\n", check);
            fclose(check);
        }
    } else {
        fclose(check);
    }

    FILE *fSrc = fopen(src, "r");
    FILE *fDest = fopen(dest, "w");

    if (fSrc && fDest) {
        int ch;
        while ((ch = fgetc(fSrc)) != EOF) {
            fputc(ch, fDest);
        }
        fclose(fSrc);
        fclose(fDest);
        printf("File copied successfully to %s\n", dest);
    } else {
        printf("Error copying file.\n");
    }

    return 0;
}

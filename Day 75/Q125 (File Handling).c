// Q125: Open an existing file in append mode and allow the user to enter a new line of text. Append the text at the end without overwriting existing content.

/*
Sample Test Cases:
Input 1:
Existing File: data.txt (Content before execution: Hello world) 
 User Input: This is appended text.
Output 1:
File updated successfully with appended text.

*/

#include <stdio.h>

int main() {
    const char *filename = "data.txt";
    FILE *fp = fopen(filename, "a");
    if (fp) {
        fputs("This is appended text.\n", fp);
        fclose(fp);
        printf("File updated successfully with appended text.\n");
    } else {
        printf("Error opening file.\n");
    }
    return 0;
}

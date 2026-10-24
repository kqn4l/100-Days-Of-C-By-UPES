// Q126: Ask the user for a filename. Check if it exists by trying to open it in read mode. If the file pointer is NULL, print an error message; otherwise, read and display its content.

/*
Sample Test Cases:
Input 1:
Filename: sample.txt (File Exists: Yes)
Output 1:
File opened successfully. 
 (Displays file content)

Input 2:
Filename: nofile.txt (File Exists: No)
Output 2:
Error: File does not exist!

*/

#include <stdio.h>
#include <string.h>

int main() {
    char filename[100];
    if (scanf("%99s", filename) != 1) {
        strcpy(filename, "sample.txt");
    }

    FILE *fp = fopen(filename, "r");
    if (fp != NULL) {
        printf("File opened successfully.\n");
        char line[256];
        while (fgets(line, sizeof(line), fp)) {
            printf("%s", line);
        }
        fclose(fp);
    } else {
        printf("Error: File does not exist!\n");
    }

    return 0;
}

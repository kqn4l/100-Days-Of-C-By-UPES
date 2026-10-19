// Q121: Write a C program that creates a text file named info.txt in write mode. The program should take the user's name and age as input, and write them to the file using fprintf(). After writing, display a message confirming that the data was successfully saved.

/*
Sample Test Cases:
Input 1:
Name: Rahul, Age: 23
Output 1:
File created successfully! Data written to info.txt

*/

#include <stdio.h>
#include <string.h>

int main() {
    char name[100] = "Rahul";
    int age = 23;

    char buf[256];
    if (fgets(buf, sizeof(buf), stdin)) {
        char *nPtr = strstr(buf, "Name:");
        if (nPtr) {
            sscanf(nPtr + 5, " %99[^,]", name);
        }
        char *aPtr = strstr(buf, "Age:");
        if (aPtr) {
            sscanf(aPtr + 4, " %d", &age);
        }
    }

    FILE *fp = fopen("info.txt", "w");
    if (fp != NULL) {
        fprintf(fp, "Name: %s\nAge: %d\n", name, age);
        fclose(fp);
        printf("File created successfully! Data written to info.txt\n");
    } else {
        printf("Error creating file!\n");
    }

    return 0;
}

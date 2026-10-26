// Q128: Read a text file and count how many vowels and consonants are in the file. Ignore digits and special characters.

/*
Sample Test Cases:
Input 1:
File: text.txt (Content: Welcome to C language)
Output 1:
Vowels: 8 
 Consonants: 10

*/

#include <stdio.h>
#include <ctype.h>

int isVowel(char ch) {
    ch = tolower(ch);
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

int main() {
    FILE *fp = fopen("text.txt", "r");
    if (!fp) {
        fp = fopen("text.txt", "w");
        if (fp) {
            fprintf(fp, "Welcome to C language\n");
            fclose(fp);
            fp = fopen("text.txt", "r");
        }
    }

    if (!fp) {
        printf("Error opening file.\n");
        return 0;
    }

    int vowels = 0, consonants = 0;
    int ch;
    while ((ch = fgetc(fp)) != EOF) {
        if (isalpha(ch)) {
            if (isVowel(ch)) vowels++;
            else consonants++;
        }
    }
    fclose(fp);

    printf("Vowels: %d \n Consonants: %d\n", vowels, consonants);
    return 0;
}

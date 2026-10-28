// Q130: Store multiple student records (name, roll number, marks) into a file using fprintf(). Then read them using fscanf() and display each record.

/*
Sample Test Cases:
Input 1:
Student 1   Name: Asha, Roll: 101, Marks: 85; Student 2   Name: Ravi, Roll: 102, Marks: 92
Output 1:
Name: Asha | Roll: 101 | Marks: 85 
 Name: Ravi | Roll: 102 | Marks: 92

*/

#include <stdio.h>

struct Student {
    char name[50];
    int roll;
    int marks;
};

int main() {
    struct Student students[] = {
        {"Asha", 101, 85},
        {"Ravi", 102, 92}
    };
    int n = 2;

    FILE *fp = fopen("students.txt", "w");
    if (fp) {
        for (int i = 0; i < n; i++) {
            fprintf(fp, "%s %d %d\n", students[i].name, students[i].roll, students[i].marks);
        }
        fclose(fp);
    }

    fp = fopen("students.txt", "r");
    if (fp) {
        char name[50];
        int roll, marks;
        while (fscanf(fp, "%49s %d %d", name, &roll, &marks) == 3) {
            printf("Name: %s | Roll: %d | Marks: %d\n", name, roll, marks);
        }
        fclose(fp);
    }

    return 0;
}

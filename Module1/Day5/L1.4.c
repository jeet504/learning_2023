/*4. Write a program to Store Data for n students in Structures Dynamically. */

#include <stdio.h>
#include <stdlib.h>

struct Student 
{
    char name[50];
    int rollno;
    float marks;
};

int main() 
{
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct Student* students = (struct Student*)malloc(n * sizeof(struct Student));

    if (students == NULL) 
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < n; i++) 
    {
        printf("\nEnter details for student %d:\n", i + 1);

        printf("Name: ");
        scanf("%s", students[i].name);

        printf("RollNo: ");
        scanf("%d", &students[i].rollno);

        printf("Marks: ");
        scanf("%f", &students[i].marks);
    }

    printf("\nStudent data:\n");
    for (int i = 0; i < n; i++) 
    {
        printf("Student %d\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("RollNo: %d\n", students[i].rollno);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }
    free(students);

    return 0;
}

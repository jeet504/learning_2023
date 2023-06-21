/*1. Assume User will be providing input in the form of a string as show below. 
Write a function to parse the string and initialize an array of structures. 

Example String : "1001 Aron 100.00" 
Example Structure : 
    struct Student{
        int rollno;
        char name[20];
        float marks;
    };

Note: User must be able define the no. of inputs/size of the array during runtime.

2. Write a function to initialize all members in the above array of structures

3. Write a function to display all members in the above array of structures

4. Write a function to sort the array of structures in descending order based on marks 

5. Write a function to perform a search operation on the array of structures based on name of the student*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student 
{
    int rollno;
    char name[20];
    float marks;
};

void parseString(const char* input, struct Student* students, int size) 
{
    char* token;
    char* str = strdup(input);

    token = strtok(str, " ");
    for (int i = 0; i < size; i++) 
    {
        students[i].rollno = atoi(token);
        token = strtok(NULL, " ");
        strncpy(students[i].name, token, 20);
        token = strtok(NULL, " ");
        students[i].marks = atof(token);
        token = strtok(NULL, " ");
    }

    free(str);
}

void initializeStudents(struct Student* students, int size) 
{
    for (int i = 0; i < size; i++) 
    {
        students[i].rollno = 0;
        strcpy(students[i].name, "");
        students[i].marks = 0.0;
    }
}

void displayStudents(const struct Student* students, int size)
{
    for (int i = 0; i < size; i++) 
    {
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }
}

int compareDescending(const void* a, const void* b)
{
    const struct Student* studentA = (const struct Student*)a;
    const struct Student* studentB = (const struct Student*)b;
    if (studentA->marks > studentB->marks) 
    return -1;
    else if (studentA->marks < studentB->marks) 
    return 1;
    else
    return 0;
}

void sortStudentsDescending(struct Student* students, int size) 
{
    qsort(students, size, sizeof(struct Student), compareDescending);
}

int searchStudentByName(const struct Student* students, int size, const char* name) 
{
    for (int i = 0; i < size; i++) 
    {
        if (strcmp(students[i].name, name) == 0) 
        {
            return i;
        }
    }
    return -1;
}

int main() 
{
    int size;
    printf("Enter the number of students: ");
    scanf("%d", &size);
    getchar();

    struct Student* students = malloc(size * sizeof(struct Student));

    char input[100];
    printf("Enter student details (Roll No Name Marks):\n");
    for (int i = 0; i < size; i++) 
    {
        fgets(input, sizeof(input), stdin);
        parseString(input, &students[i], 1);
    }

    printf("\nDisplaying student details:\n");
    displayStudents(students, size);

    sortStudentsDescending(students, size);

    printf("\nDisplaying student details after sorting by marks (descending order):\n");
    displayStudents(students, size);

    char searchName[20];
    printf("\nEnter the name of the student to search: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0';  // Remove the trailing newline character

    int foundIndex = searchStudentByName(students, size, searchName);
    if (foundIndex != -1) 
    {
        printf("\nStudent found at index %d:\n", foundIndex);
        printf("Roll No: %d\n", students[foundIndex].rollno);
        printf("Name: %s\n", students[foundIndex].name);
        printf("Marks: %.2f\n", students[foundIndex].marks);
    } else 
        printf("\nStudent not found.\n");

    free(students);
    return 0;
}

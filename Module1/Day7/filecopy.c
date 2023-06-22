/*1. File Copy: Write a C program to copy a file using file operations*/

#include <stdio.h>
#define BUFFER_SIZE 4096

int main() 
{
    FILE *file1, *file2;
    char FileName1[100], FileName2[100];
    char buffer[BUFFER_SIZE];
    size_t bytesRead;

    printf("Enter the source file name: ");
    scanf("%s",FileName1);

    file1 = fopen(FileName1, "rb");
    if (file1 == NULL) 
    {
        printf("Unable to open the source file.\n");
        return 1;
    }

    printf("Enter the destination file name: ");
    scanf("%s",FileName2);

    file2 = fopen(FileName2, "wb");
    if (file2 == NULL) 
    {
        printf("Unable to create the destination file.\n");
        fclose(file1);
        return 1;
    }

   
    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, file1)) > 0) 
    {
        fwrite(buffer, 1, bytesRead, file2);
    }

    printf("File copied successfully.\n");

    
    fclose(file1);
    fclose(file2);

    return 0;
}


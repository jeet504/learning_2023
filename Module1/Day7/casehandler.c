/*2. Case Handler:
Write a C program to copy a file by considering the user option to handle the text case
-u, to change file content to Upper Case
-l, to change file content to Lower Case
-s, to change file content to Sentence Case
if no options are passed then it should be a normal copy

Example, say we have a file f1 with the following content
f1:
-----------------------
This is the file data
testing Case copy
application
-----------------------

./cp -s f1 f2
f2:
-----------------------
This Is The File Data
Testing Case Copy
Application
-----------------------

./cp -l f1 f3
f3:
-----------------------
this is the file data
testing case copy
application
-----------------------

./cp -u f1 f4
f4:
-----------------------
THIS IS THE FILE DATA
TESTING CASE COPY
APPLICATION
-----------------------

./cp f1 f5
Should perform a normal copy*/


#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define BUFFER_SIZE 4096

void toUpperCase(char *str) 
{
    while (*str) 
    {
        *str = toupper((unsigned char)*str);
         str++;
    }
}

void toLowerCase(char *str) 
{
    while (*str) 
    {
        *str = tolower((unsigned char)*str);
         str++;
    }
}

void toSentenceCase(char *str) 
{
    int isFirstCharacter = 1;
    while (*str) 
    {
        if (isFirstCharacter) 
        {
            *str = toupper((unsigned char)*str);
            isFirstCharacter = 0;
        } 
        else
            *str = tolower((unsigned char)*str);

        if (*str == '.' || *str == '!' || *str == '?')
            isFirstCharacter = 1;
        str++;
    }
}

int main(int argc, char *argv[]) 
{
    if (argc < 3) 
    {
        printf("Insufficient arguments.\n");
        printf("Usage: %s <option> <source_file> <destination_file>\n", argv[0]);
        return 1;
    }

    FILE *file1, *file2;
    char FileName1[100], FileName2[100];
    char buffer[BUFFER_SIZE];
    size_t bytesRead;
    int option = argv[1][1];

    if (option != 'u' && option != 'l' && option != 's')
       option = 0;
    
    strcpy(FileName1, argv[2]);
    strcpy(FileName2, argv[3]);

    file1 = fopen(FileName1, "rb");
    if (file1 == NULL) 
    {
        printf("Unable to open the source file.\n");
        return 1;
    }

    file2= fopen(FileName2, "wb");
    if (file2 == NULL) 
    {
        printf("Unable to create the destination file.\n");
        fclose(file1);
        return 1;
    }

    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, file1)) > 0) 
    {
        if (option == 'u') 
            toUpperCase(buffer);
        else if (option == 'l') 
            toLowerCase(buffer);
        else if (option == 's') 
            toSentenceCase(buffer);
    
        fwrite(buffer, 1, bytesRead, file2);
    }
    printf("File copied successfully.\n");
    fclose(file1);
    fclose(file2);
    return 0;
}

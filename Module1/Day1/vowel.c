/*3. Write a function to find if a give character is vowel using switch case statements, 
    - If vowel, return 1
    - If not vowel, return 0;

In main print,
"Vowel" if return value is 1
"Not Vowel" if return value is 1*/


#include <stdio.h>

int vowel(char ch)
{
    ch = tolower(ch);
    switch(ch)
    {
        case 'a':
        return 1;
        break;
        case 'e':
        return 1;
        break;
         case 'i':
        return 1;
        break;
         case 'o':
        return 1;
        break;
         case 'u':
        return 1;
        break;
        default:return 0;
    }
}

int main()
{
    char ch;
    int a;
    scanf("%c",&ch);
    a = vowel(ch);
    if(a == 1)
    printf("Vowel");
    else
    printf("Not Vowel");
    return 0;
    
}

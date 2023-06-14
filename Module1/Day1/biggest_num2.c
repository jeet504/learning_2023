/*1. Write a function to find biggest of 2 numbers using 
    - ternary operator*/
    
    
#include <stdio.h>

int main()
{
    int a,b;
    scanf("%d",&a);
    scanf("%d",&b);
    (a>b) ? printf("Biggest:%d",a) : printf("Biggest:%d",b);
    return 0;
}

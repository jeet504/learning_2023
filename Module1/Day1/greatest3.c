/*1. Write a function to return the greatest of 3 number using if else if*/


#include <stdio.h>

int greatest(int a, int b, int c)
{
    if(a>b && a>c)
    return a;
    else if(b>a && b>c)
    return b;
    else
    return c;
}

int main()
{
    int a,b,c;
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    printf("Greatest:%d",greatest(a,b,c));
    return 0;
}

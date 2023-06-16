/*5. Write a program to find both smallest and largest digits in given n numbers
For example let's say we have n = 3, and n1 = 8, n2 = 156, n3 = 123450, the result will be "Not Valid", 1 and 6, 0 and 5*/

#include <stdio.h>
int findSmallestDigit(int num) 
{
    int smallest = 9;
    int  c=0;
    while (num > 0) 
    {
        int d = num % 10;
        c++;
        if (d < smallest) 
        {
            smallest = d;
        }
        num /= 10;
    }
    if(c ==1)
    return 1;
    else
    return smallest;
}

int findLargestDigit(int num) 
{
    int largest = 0;
    int c = 0;
    while (num > 0) 
    {
        int d = num % 10;
        c++;
        if (d > largest) 
        {
            largest = d;
        }
        num /= 10;
    }
    if(c==1)
    return 1;
    else
    return largest;
}

int main() 
{
    int n;
    scanf("%d", &n);
    int num[n];
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &num[i]);
    }
    
    for (int i = 0; i < n; i++) 
    {
       int smallest = findSmallestDigit(num[i]);
       int largest = findLargestDigit(num[i]);
       if(smallest == 1 && largest == 1)
       printf("%d-Not Valid\n\n",num[i]);
       else
       {
       printf("%d-Smallest digit: %d\n", num[i],smallest);
       printf("     Largest digit: %d\n",largest);
       printf("\n");
       }
    }
    
    return 0;
}

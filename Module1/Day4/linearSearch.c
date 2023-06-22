#include<stdio.h>
#define MAX 20
int linearSearch(int element[],int size,int k);
   int main()
   {
     int a[MAX],n,temp,x,i;
     printf("enter the size of the array has to <= 20: ");
     scanf("%d",&n);
     for(i=0;i<n;i++)
      {
        printf("enter at a[%d]: ",i);
        scanf("%d",&a[i]);
      }
       printf("\nenter the element to be searched: ");
       scanf("%d",&x);
       temp = linearSearch(a,n,x);
       if(temp==-1)
       printf("\nThe Number is Not Present");
       else
       printf("\nThe Number is Present at %d location",temp);
       return 0;
    }
int linearSearch(int element[],int size,int k)
{
    int index;
    for(index=0;index<size;index++)
    {
      if(element[index]==k)
      {
         return index;
      }
    }
     return -1;
}
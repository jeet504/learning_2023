#include<stdio.h>
#define MAX 50
void bubbleSort(int element[],int s);
  int main()
  {
     int a[MAX],n;
     int i,j,temp;
      printf("Enter the size of array: ");
      scanf("%d",&n);
      for(i=0; i<n; i++)
      {
        printf("\na[%d] : ",i);
        scanf("%d",&a[i]);
      }
      bubbleSort(a,n);
       printf("\nThe Sorted Array is:-\n");
       for(i=0; i<n; i++)
       {
         printf("\na[%d] = %d\n",i, a[i]);
       }
       return 0;
  }
void bubbleSort(int element[],int s)
{
    int i,j,temp;
    for(i=0;i<s-1;i++)
    {
      for(j=0;j<s-1-i;j++)
      {
           if(element[j]>element[j+1])
           {
               temp=element[j];
               element[j]=element[j+1];
               element[j+1]=temp;
           }
       }
   }
}

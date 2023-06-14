/*3. Write a program to read the 
    - Roll No
    - Name (Note, you should read full name of the student including initials)
    - Marks of Physics, Math and Chemistry
    Calculate the total, percentage and print the summary.*/
    
    
#include <stdio.h>
#include <string.h>
int main()
{  
   float total,percentage;
   int roll_no;
   scanf("%d",&roll_no);
   char name[20],temp;
   scanf("%c",&temp);
   scanf("%[^\n]",name);
   float p;
   scanf("%f",&p);
   float m;
   scanf("%f",&m);
   float c;
   scanf("%f",&c);
   total = p+m+c;
   percentage = (total/300)*100;
   printf("Roll No.:%d\n",roll_no);
   printf("Name:%s\n",name);
   printf("Physics:%f\n",p);
   printf("Math:%f\n",m);
   printf("Chemistry:%f\n",c);
   printf("Total:%f\n",total);
   printf("Percentage:%f",percentage);
   return 0;
}

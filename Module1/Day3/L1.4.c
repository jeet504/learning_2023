/*4. Find the largest number by deleting single digit in a 4 digit number 5872 - 872, 9856 - 986

Concepts to be used.
- Loops
- Operators*/

#include <stdio.h>

int findLargestNumber(int num) 
{
    int largest = 0;
    char str[5];
    sprintf(str, "%d", num);
    for (int i = 0; i < 4; i++) 
    {
        int c = 0;
        for (int j = 0; j < 4; j++) 
        {
            if (j != i) 
            {
                c = c* 10 + (str[j] - '0');
            }
        }
        if (c > largest) {
            largest = c;
        }
    }
    
    return largest;
}

int main() 
{
    int num;
    scanf("%d", &num);
    int largestNumber = findLargestNumber(num);
    printf("The largest number after deleting a single digit is: %d\n", largestNumber);
    return 0;
}



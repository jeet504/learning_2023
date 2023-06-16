/*2. Prints Bits:
Scan a 32bit integer and prints its bits.

Concepts to be used.
- Loops
- Bitwise Operators*/

#include <stdio.h>

void printBits(unsigned int num) 
{
    unsigned int m = 1 << 31;
    
    for (int i = 0; i < 32; i++) 
    {
        if (num & m) 
        {
            printf("1");
        } else 
        {
            printf("0");
        }
        m >>= 1;
    }
    printf("\n");
}

int main() 
{
    unsigned int n;
    printf("Enter a 32-bit integer: ");
    scanf("%u", &n);
    printf("Bits of the number: ");
    printBits(n);
    return 0;
}

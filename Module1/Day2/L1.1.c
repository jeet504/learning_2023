/*1. Write a program to print exponent part of double variable in hexadecimal and binary format.
lets say we have x = 0.7, the exponent in hex is 0x3FE and 0b01111111110
You may use the below link to validate you output
https://baseconvert.com/ieee-754-floating-point

Topics to be covered
- Pointers
- Bitwise Operators*/

#include <stdio.h>
void Exponent(double x) 
{
    unsigned long long *ptr = (unsigned long long *)&x; // Pointer to the memory of x
    unsigned long long exponent = (*ptr & 0x7FF0000000000000) >> 52; // Extracting the exponent bits

    // Printing exponent in hexadecimal format
    printf("Exponent (hex): 0x%llX\n", exponent);

    // Printing exponent in binary format
    printf("Exponent (binary): 0b");
    for (int i = 11; i >= 0; i--) 
    {
        printf("%d", (exponent >> i) & 1);
    }
    printf("\n");
}

int main() 
{
    double x = 0.7;
    Exponent(x);
    return 0;
}

/*2. Write a C program that uses functions to perform the following operations: 
     i) Reading a complex number 
     ii) Writing a complex number 
     iii) Addition of two complex numbers 
     iv) Multiplication of two complex numbers 
  (Note: represent complex number using a structure.*/

#include <stdio.h>

struct complex 
{
    double real;
    double imaginary;
};


struct complex readComplex() 
{
    struct complex c;

    printf("Enter the real part: ");
    scanf("%lf", &c.real);

    printf("Enter the imaginary part: ");
    scanf("%lf", &c.imaginary);

    return c;
}


void writeComplex(struct complex c) 
{
    printf("Complex number: %.2f + %.2fi\n", c.real, c.imaginary);
}


struct complex addComplex(struct complex c1, struct complex c2) 
{
    struct complex sum;

    sum.real = c1.real + c2.real;
    sum.imaginary = c1.imaginary + c2.imaginary;

    return sum;
}

struct complex multiplyComplex(struct complex c1, struct complex c2) 
{
    struct complex product;

    product.real = c1.real * c2.real - c1.imaginary * c2.imaginary;
    product.imaginary = c1.real * c2.imaginary + c1.imaginary * c2.real;

    return product;
}

int main() 
{
    struct complex c1, c2, sum, product;

    printf("Enter the first complex number:\n");
    c1 = readComplex();

    printf("Enter the second complex number:\n");
    c2 = readComplex();

    writeComplex(c1);
    writeComplex(c2);
    
    sum = addComplex(c1, c2);
    printf("Sum of the complex numbers:\n");
    writeComplex(sum);

    product = multiplyComplex(c1, c2);
    printf("Product of the complex numbers:\n");
    writeComplex(product);

    return 0;
}

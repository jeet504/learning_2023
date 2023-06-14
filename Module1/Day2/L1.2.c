/*2. Write a program to swap any type of data passed to an function.

Topics to be covered
- Pointers
- Type Casting*/


#include <stdio.h>
void swap(void* a, void* b, size_t size)
{
    void* temp = malloc(size);
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
    free(temp);
}

int main() 
{
    int a = 10, b = 20;
    printf("Before swap: a = %d, b = %d\n", a, b);
    swap(&a, &b, sizeof(int));
    printf("After swap: a = %d, b = %d\n", a, b);

    char c = 'X', d = 'Y';
    printf("Before swap: c = %c, d = %c\n", c, d);
    swap(&c, &d, sizeof(char));
    printf("After swap: c = %c, d = %c\n", c, d);

    double x = 3.14, y = 2.71;
    printf("Before swap: x = %f, y = %f\n", x, y);
    swap(&x, &y, sizeof(double));
    printf("After swap: x = %f, y = %f\n", x, y);

    return 0;
}

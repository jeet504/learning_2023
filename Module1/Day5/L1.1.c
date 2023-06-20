/*1. Use structures to find the volume and the total surface area of the box. 
   You need to access the members of the structure with the help of a structure pointer:
    a. With the help of (*) asterisk or indirection operator and (.) dot operator.
    b. With the help of ( -> ) Arrow operator using pointer as well as dot representation.*/

#include <stdio.h>

struct Box 
{
    double length;
    double width;
    double height;
};

double calculateVolume(struct Box* ptr) 
{
    return ptr->length * ptr->width * ptr->height;
}

double calculateSurfaceArea(struct Box* ptr) 
{
    double length = ptr->length;
    double width = ptr->width;
    double height = ptr->height;
    
    return 2 * (length * width + length * height + width * height);
}

int main() 
{
    struct Box myBox;
    struct Box* ptr = &myBox;

    
    scanf("%lf",&ptr->length);
    scanf("%lf",&ptr->width);
    scanf("%lf",&ptr->height);

   
    double volume = calculateVolume(ptr);
    double surfaceArea = calculateSurfaceArea(ptr);

    printf("Volume of the box: %.2f\n", volume);
    printf("Surface area of the box: %.2f\n", surfaceArea);

    return 0;
}

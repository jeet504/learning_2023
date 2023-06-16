#include <stdio.h>
void encode(char* str) 
{
    int i = 0;
    while (str[i] != '\0') 
    {
        str[i] += 2;  // Shift each character by 2 positions
        i++;
    }
}

void decode(char* str) 
{
    int i = 0;
    while (str[i] != '\0') 
    {
        str[i] -= 2;  // Shift each character back by 2 positions
        i++;
    }
}

int main() 
{
    char str[100];
    scanf("%s",str);
    // Encode the string
    encode(str);
    printf("Encoded string: %s\n", str);

    // Decode the string
    decode(str);
    printf("Decoded string: %s\n", str);

    return 0;
}






/*
Exercise RS-1: Write a C program to produce the same output as this Python program using the %d and %s features of the printf() function:

print('Hello world')
print('Answer', 17)
print('Name', 'Sarah')
*/

#include <stdio.h>

int main()
{
    printf("Hello world\n");
    printf("Answer %d\n", 17);
    printf("Name %s\n", "Sarah");
    return 0;
}

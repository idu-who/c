/*
Exercise RS-6: Write a C program to produce the same output as this Python program using a 'for' loop.

for i in range(5) :
    print(i)
*/

#include <stdio.h>

int main()
{
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", i);
    }
    return 0;
}

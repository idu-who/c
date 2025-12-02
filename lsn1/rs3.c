/*
Exercise RS-3: Write a C program equivalent to this Python program:

print('Enter name')
name = input()
print('Hello', name)
*/

#include <stdio.h>

int main()
{
    char name[100];
    printf("Enter name\n");
    scanf("%100s", name);
    printf("Hello %s\n", name);
    return 0;
}

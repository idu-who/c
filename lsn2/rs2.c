/*
Exercise RS-2: Write a C program equivalent to this Python program:

print('Enter US Floor')
usf = int(input())
euf = usf - 1
print('EU Floor', euf)
*/

#include <stdio.h>

int main() {
    int usf, euf;
    printf("Enter US Floor\n");
    // we pass usf by reference to allow scanf to set it's value
    scanf("%d", &usf);
    euf = usf - 1;
    printf("EU Floor %d\n", euf);
    return 0;
}

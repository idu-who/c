/*
Exercise RS-3: Write a C program equivalent to this Python program:

print('Enter name')
name = input()
print('Hello', name)
*/

#include <stdio.h>

int main() {
    char name[100];
    printf("Enter name\n");
    /*
    character arrays are always NULL terminated, thus, a char array of size
    10 can store 9 characters + a '\0' character at the end.
    when using scanf, C does not check if the length of input is larger than the
    size of the char array. As a rule of thumb, use a width of (size - 1) in
    scanf. scanf always appends a '\0' after the read characters. neglecting
    this can cause a buffer overflow.
    */
    scanf("%99s", name);
    printf("Hello %s\n", name);
    return 0;
}

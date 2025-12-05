/*
Exercise RS-5: Write a C program to implement this Python program, using the
fgets function instead of scanf.

print('Enter line')
line = input()
print('Line:', line)
*/

#include <stdio.h>

int main() {
    char line[1000];
    printf("Enter line\n");
    fgets(line, 1000, stdin);
    printf("Line: %s", line);
    return 0;
}

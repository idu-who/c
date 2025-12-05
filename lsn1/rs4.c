/*
Exercise RS-4: Write a C program equivalent to this Python program:

print('Enter line')
line = input()
print('Line:', line)
*/

#include <stdio.h>

int main() {
    char line[1000];
    printf("Enter line\n");
    /*
    by defualt scanf stops reading input on any white space.
    [^\n] is like a regex that says read everything except \n
    */
    scanf("%[^\n]999s", line);
    printf("Line: %s\n", line);
    return 0;
}

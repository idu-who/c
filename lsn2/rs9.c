/*
Exercise RS-9: Write a C function to implement this Python code:

def mymult(a,b):
    c = a * b
    return c
*/

#include <stdio.h>

int mymult(int a, int b);

int main() {
    int retval = mymult(6, 7);
    printf("Answer: %d\n", retval);
    return 0;
}

int mymult(int a, int b) { return a * b; }

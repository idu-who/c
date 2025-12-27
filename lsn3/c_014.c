/*
Program which copies it's input to it's output one character at a time.
*/

#include <stdio.h>

int main() {
    /* using int instead of char to allow c to store EOF
    EOF is defined as either -1 or 0 in stdio.h
    mordern systems use -1. */
    // in C char is an alias for an 8-bit int (signed/unsigned - implementation dependant)
    int c;

    /* mordern compiles use canonical mode to buffer input 1 line at time
    due to this the copy is only displayed after pressing enter. */
    while ((c = getchar()) != EOF) {
        putchar(c);
    }
    return 0;
}

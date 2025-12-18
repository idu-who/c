/*
K&R Exercise 1-7. Write a program to copy its input to its output, replacing
each string of one or more blanks by a single blank.
*/

#include <stdio.h>

unsigned int is_blank(char c);

int main() {
    int c;
    char prv_c = '\0';

    while ((c = getchar()) != EOF) {
        if (!(is_blank(c) && is_blank(prv_c)))
            putchar(c);
        prv_c = c;
    }
    return 0;
}

unsigned int is_blank(char c) { return (c == ' ' || c == '\t' || c == '\n'); }

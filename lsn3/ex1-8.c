/*
K&R Exercise 1-8. Write a program to replace each tab by the three-character
sequence >, backspace, -, which prints as >, and each backspace by the similar
sequence <. This makes tabs and backspaces visible.
*/

#include <stdio.h>

int main() {
    int c;

    // doesn't work as intended in mordern terminals
    while ((c = getchar()) != EOF) {
        if (c == '\t')
            printf("->");
        else if (c == '\b')
            printf("<-");
    }
    return 0;
}

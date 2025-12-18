/*
K&R Exercise 1-6. Write a program to count blanks, tabs, and newlines.
*/

#include <stdio.h>

int main() {
    int input_char, num_spaces, num_tabs, num_newlines;
    num_spaces = num_tabs = num_newlines = 0;

    while ((input_char = getchar()) != EOF) {
        if (input_char == ' ')
            ++num_spaces;
        else if (input_char == '\t')
            ++num_tabs;
        else if (input_char == '\n')
            ++num_newlines;
    }
    printf("spaces: %d\n", num_spaces);
    printf("tabs: %d\n", num_tabs);
    printf("new lines: %d\n", num_newlines);
    return 0;
}

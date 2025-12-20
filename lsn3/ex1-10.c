/*
K&R Exercise 1-10. Write a program which prints the words in its input, one per
line.
*/

#include <stdbool.h>
#include <stdio.h>

#define BUFFER_SIZE 30

bool is_blank(char c);
void print_n_reset(char word[], unsigned int *i);

int main() {
    // character
    int c;

    // word string
    char word[BUFFER_SIZE];
    unsigned int i = 0; // index

    // flag to skip long words
    bool skip_flag = false;

    while ((c = getchar()) != EOF) {
        if (is_blank(c)) {
            if (skip_flag)
                skip_flag = false;

            // print if word is not empty
            if (i != 0)
                print_n_reset(word, &i);
        } else if (!skip_flag) {
            if (i < BUFFER_SIZE - 1)
                word[i++] = c;
            else {
                skip_flag = true;
                i = 0; // reset index
                fprintf(stderr, "word skipped - too long\n");
            }
        }
    }

    // print if leftover word (in case line hit EOF without blank character)
    if (i != 0)
        print_n_reset(word, &i);

    return 0;
}

bool is_blank(char c) { return (c == ' ' || c == '\t' || c == '\n'); }

void print_n_reset(char word[], unsigned int *i) {
    word[*i] = '\0'; // null-terminate
    printf("[%s]\n", word);
    *i = 0; // reset index
}

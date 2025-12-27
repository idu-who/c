/*
K&R Exercise 1-11. Revise the word count program to use a better definition of
"word," for example, a sequence of letters, digits and apostrophes that begins
with a letter.
*/

/*
valid words:
hello
s1xn1ne
wasn't
abcd789'xyz

Example:
input        | output | words
hello 0world | 2      | hello,world
we 'liv 'fri | 3      | we,liv,fri
*/

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

int main() {
    int c, wc = 0;
    bool in_word = false;

    while ((c = getchar()) != EOF) {
        if (!isalnum(c) && c != '\'')
            in_word = false;
        else if (isalpha(c) && !in_word) {
            in_word = true;
            ++wc;
        }
    }

    printf("%d\n", wc);

    return 0;
}

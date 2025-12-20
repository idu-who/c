/*
Write a program to count lines, words and characters. A word is any sequence of
characters that does not contain a space, tab or newline.
*/

/*
Current implementation - bool in_word
Previous implementation - char prv_c

Current implementation does ++wc at the beginning of the word.
if (!is_blank(c) && !in_word) { ++wc; in_word = true; }

Previous implementation did ++wc at the end of the word.
if (is_blank(c) && !is_blank(prv_c)) { ++wc; }

issue with previous implementation:
E.g input: 'hello world^D' (^D is EOF)

in this example, previous implementation would return incorrect
word count since the loop would exit before counting 'world'.
*/

#include <stdbool.h>
#include <stdio.h>

bool is_blank(char c);

int main() {
    // character, line_count, word_count, character_count
    int c, lc, wc, cc;
    // is_in_word flag
    bool in_word = false;

    lc = wc = cc = 0;
    while ((c = getchar()) != EOF) {
        ++cc;

        if (c == '\n')
            ++lc;

        if (is_blank(c))
            in_word = false;
        else if (!in_word) {
            in_word = true;
            ++wc;
        }
    }

    printf("%d %d %d\n", cc, wc, lc);
    // printf("\ncharacters: %d\n", cc);
    // printf("words: %d\n", wc);
    // printf("lines: %d\n", lc);

    return 0;
}

bool is_blank(char c) { return (c == ' ' || c == '\t' || c == '\n'); }

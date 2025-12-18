/*
Count lines in input.
*/

#include <stdio.h>

int main() {
    int c, nl = 0; // character, number of lines

    while ((c = getchar()) != EOF) {
        if (c == '\n')
            ++nl;
    }

    printf("%d\n", nl);
    return 0;
}

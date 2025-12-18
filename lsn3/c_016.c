/*
Count input characters.
*/

#include <stdio.h>

int main() {
    // using long for larger range
    long nc = 0; // number of characters

    while (getchar() != EOF)
        ++nc;

    printf("%ld\n", nc);
    return 0;
}

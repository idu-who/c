/*
Read a file and print in uppercase.

Python example:
hand = open('romeo.txt')
for line in hand:
    print(line.strip().upper())
*/

#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main() {
    char line[1000];
    FILE *hand = fopen("romeo.txt", "r");

    if (hand == NULL) {
        printf("romeo.txt failed to open.\n");
    } else {
        while (fgets(line, 1000, hand) != NULL) {
            for (size_t i = 0; i < strlen(line); i++) {
                putchar(toupper(line[i]));
            }
        }
    }
    return 0;
}

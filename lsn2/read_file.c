/*
Read a file.

Python example:
hand = open('romeo.txt')
for line in hand:
    print(line.strip())
*/

#include <stdio.h>

int main() {
    char line[1000];
    FILE *hand = fopen("romeo.txt", "r");

    if (hand == NULL)
        printf("romeo.txt failed to open.\n");
    else {
        while (fgets(line, 1000, hand) != NULL)
            printf("%s", line);

        fclose(hand);
    }
    return 0;
}

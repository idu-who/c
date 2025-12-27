/*
Read strings from user and concat.

Python example:
print('Enter two strings');
first = input()
second = input()
print(first + " & " + second)
*/

#include <stdio.h>
#include <string.h>

void flushinp();

int main() {
    char first[100], second[100];
    printf("Enter two strings\n");
    scanf("%99[^\n]s", first);
    flushinp(); // clearing left-over characters
    scanf("%99[^\n]s", second);

    printf("%s & %s\n", first, second); // without concat

    // (100 - 1) + (100 - 1) + 1 + 3 [1's for '\0'] [3 for " & "]
    char combined[202];
    // VLA (Variable Length Array) +4 for len(" & ") + '\0'
    // char combined[strlen(first) + strlen(second) + 4];
    strcpy(combined, first);
    strcat(combined, " & ");
    strcat(combined, second);
    printf("%s\n", combined);
    return 0;
}

void flushinp() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

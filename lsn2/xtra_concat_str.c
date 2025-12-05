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

int main() {
    char first[100], second[100];
    printf("Enter two strings\n");
    scanf("%[^\n]99s", first);
    getchar(); // clearing left-over \n from stdin
    scanf("%[^\n]99s", second);

    printf("%s & %s\n", first, second); // without concat

    // (100 - 1) + (100 - 1) + 1 + 3 [1's for '\0'] [3 for " & "]
    char combined[202];
    // dynamically sized arr. +4 for len(" & ") + '\0'
    // char combined[strlen(first) + strlen(second) + 4];
    strcpy(combined, first);
    strcat(combined, " & ");
    strcat(combined, second);
    printf("%s\n", combined);
    return 0;
}

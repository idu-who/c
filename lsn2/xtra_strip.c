/*
Strip whitespaces from string and print.

Python example:
s1 = "   Hello   World    "
print('-'+s1.rstrip()+'-')
*/

#include <ctype.h>
#include <stdio.h>
#include <string.h>

void str_rstrip(char str[]) {
    size_t i, last_char_i; // last non whitespace char index
    for (i = 0, last_char_i = 0; i < strlen(str); i++) {
        if (isspace(str[i]) == 0)
            last_char_i = i;
    }
    if (!(last_char_i + 1 == i))
        str[last_char_i + 1] = '\0';
    return;
}

void str_lstrip(char str[]) {
    size_t char_i, ws_char_i;
    size_t found = 0;
    for (char_i = 0, ws_char_i = 0; char_i < strlen(str); char_i++) {
        if (!found && isspace(str[char_i]) != 0)
            continue;
        if (char_i == ws_char_i)
            return;

        found = 1;
        str[ws_char_i++] = str[char_i];
    }
    str[ws_char_i] = '\0';
    return;
}

int main() {
    char s1[] = "   Hello   World    ";
    str_rstrip(s1);
    str_lstrip(s1);
    printf("-%s-\n", s1);
    return 0;
}

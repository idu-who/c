// attempt 1 based on problem statement

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int minval = 999999999, maxval = -999999999;
    while (1) {
        char line[1000];
        gets(line); // deprecated
        if (strcmp(line, "done") == 0)
            break;

        int val = atoi(line);
        if (val < minval)
            minval = val;
        if (val > maxval)
            maxval = val;
    }
    printf("Maximum %d\n", maxval);
    printf("Minimum %d\n", minval);
    return 0;
}

// attempt 2 based on problem statement and error message from autochecker

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int first = 1;
    int minval, maxval;
    char line[1000];

    // gets() is deprecated
    while (gets(line) != NULL)
    {
        if (strcmp(line, "done") == 0)
            break;

        int val = atoi(line);
        if (first || val < minval)
            minval = val;
        if (first || val > maxval)
            maxval = val;
        first = 0;
    }
    printf("Maximum %d\n", maxval);
    printf("Minimum %d\n", minval);
    return 0;
}

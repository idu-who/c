/*
K&R Exercise 1-5. Modify the temperature conversion program to print the table
in reverse order, that is, from 300 degrees to 0.
*/

#include <stdio.h>

#define UPPER 300
#define LOWER 0
#define STEP 20

int main() {
    printf("Fahrenheit\t\tCelsius\n");
    for (int fahr = UPPER; fahr >= LOWER; fahr -= STEP) {
        printf("%10d\t\t%7.2f\n", fahr, (5.0F / 9.0F) * (fahr - 32));
    }
    return 0;
}

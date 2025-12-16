/*
K&R Exercise 1-4. Write a program to print the corresponding Celsius to Fahrenheit
table.
*/

#include <stdio.h>

int main() {
    float convert_c_to_f(float celsius);

    float celsius, fahrenheit;

    printf("Celsius\t\tFahrenheit\n");
    for (celsius = 0; celsius <= 300; celsius += 20) {
        fahrenheit = convert_c_to_f(celsius);

        printf("%7.0f\t\t%10.2f\n", celsius, fahrenheit);
    }
}

float convert_c_to_f(float celsius) {
    float fahrenheit = celsius * (9.0 / 5.0) + 32;
    return fahrenheit;
}

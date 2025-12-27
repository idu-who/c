/*
K&R Exercise 1-3. Modify the temperature conversion program to print a heading
above the table. Check the sample output for the required format of the heading.

print Fahrenheit-Celsius table for f = 0, 20, ..., 300
*/

#include <stdio.h>

float convert_f_to_c(float fahrenheit);

int main() {
    float celsius, fahrenheit;

    printf("Fahrenheit\t\tCelsius\n");
    for (fahrenheit = 0; fahrenheit <= 300; fahrenheit += 20) {
        celsius = convert_f_to_c(fahrenheit);

        /*
            "%x.df" format specifier
            - x is for the minimum display width. prints spaces to pad if value
              is under the desired width.
            - .d is for number of decimal places to display.
        */
        printf("%10.0f\t\t%7.2f\n", fahrenheit, celsius);
    }
}

float convert_f_to_c(float fahrenheit) {
    /*
        explicitly doing floating point division since
        integer division truncates the fractional part.
        also, using F for float constants. C defaults to double constants.
    */
    float celsius = (5.0F / 9.0F) * (fahrenheit - 32);
    return celsius;
}

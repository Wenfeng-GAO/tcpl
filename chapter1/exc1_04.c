/**
 * Solution for Exercise 1-4, Chapter 1.
 * Write a program to print the corresponding Celsius to Fahrenheit table,
 * with a heading above the table.
 */

#include <stdio.h>
int main()
{
    float celsius, fahr;
    float upper, lower, step;

    lower = 0;
    upper = 300;
    step = 20;

    // Print the heading above the table
    printf("Celsius\t\tFahrenheit\n");

    celsius = lower;
    while (celsius <= upper) {
        fahr = celsius * 9 / 5 + 32;
        printf("%3.0f\t\t%6.1f\n", celsius, fahr);
        celsius += step;
    }

    return 0;
}



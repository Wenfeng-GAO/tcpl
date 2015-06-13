/**
 * Solution for Exercise 1-5, Chapter 1.
 * Modify the temperature conversion program to print the 
 * table in reverse order, that is, from 300 degrees to 0.
 */

#include <stdio.h>
#define UPPER 300
#define LOWER 0
#define STEP 20

int main()
{
    for (float fahr = UPPER; fahr >= LOWER; fahr -= STEP)
        printf("%3.0f\t\t%6.1f\n", fahr, (5.0/9.0)*(fahr-32));

    return 0;
}

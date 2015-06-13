/**
 * Solution for Exercise 1-12, Chapter 1.
 * Write a program that prints its input one word per line.
 */

#include <stdio.h>

/************** Version 1 ************************
#define IN 1
#define OUT 0

int main()
{
    int c, state = IN;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            putchar('\n');
        }
        if (state == IN)
            putchar(c);
    }
    return 0;
}
        
************************************************/

/************* Version 2 **********************/
int main()
{
    int c, newlineStarted = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (!newlineStarted) {
                putchar('\n');
                newlineStarted = 1;
            }
        } else {
            putchar(c);
            newlineStarted = 0;
        }
    }
    return 0;
}

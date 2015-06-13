/**
 * Solution for Exercise 1-9, Chapter 1.
 * Write a program to copy its input to its output, replacing
 * each string of one or more blanks by a single blank.
 */

#include <stdio.h>
int main()
{
    int c,  hasBlank = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if (!hasBlank) {
                putchar(c);
                hasBlank = 1;
            }
        } else {
            putchar(c);
            hasBlank = 0;
        }
    }
    return 0;
}

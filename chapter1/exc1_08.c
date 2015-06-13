/**
 * Solution for Exercise 1-8, Chapter 1.
 * Write a program to count blanks, tabs, 
 * and newlines.
 */

#include <stdio.h>
int main()
{
    int c; // Input char
    int nb, nt, nl; // Number of blanks, tabs and newlines

    nb = 0;
    nt = 0;
    nl = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ')
            nb++;
        else if (c == '\t')
            nt++;
        else if (c == '\n')
            nl++;
    }
    printf("Num of blanks: %d\nNum of tabs: %d\nNum of newlines: %d\n", nb, nt, nl);
    return 0;
}

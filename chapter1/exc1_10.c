/**
 * Solution for Exercise 1-10, Chapter 1.
 * Write a program to copy its input to its output, replacing
 * each tab by \t, each backspace \b, and each backslash by \\.
 * This makes tabs and backspaces visible in an unambiguous way.
 */

#include <stdio.h>
#define SHOW_TAB printf("\\t")
#define SHOW_BACKSPACE printf("\\b")
#define SHOW_BACKSLASH printf("\\\\")

int main()
{
    int c;
    while ((c = getchar()) != EOF) {
        if (c == '\t')
            SHOW_TAB;
        else if (c == '\b')
            SHOW_BACKSPACE;
        else if (c == '\\')
            SHOW_BACKSLASH;
        else
            putchar(c);
    }
    return 0;
}


/**
 * Solution for Exercise 1-17, Chapter 1.
 * Write a program to print all input lines that are longer
 * than 80 characters.
 */

#include <stdio.h>

#define MAX 1000 /* Maximum input lines */

int getlines(char line[], int lim);

int main() 
{
    int len; // Current line length
    char line[MAX]; // Current input line

    while ((len = getlines(line, MAX)) > 0) {
        if (len > 30)
            printf("%s", line);
    }

    return 0;
}

/* Getlines: store input lines, return the length of the line */
int getlines(char line[], int lim)
{
    int c, i;
    for (i = 0; i < MAX-1 && (c=getchar())!=EOF && c!='\n'; ++i) 
        line[i] = c;
    if (c == '\n') 
        line[i++] = c;
    line[i] = '\0';

    return i;
}



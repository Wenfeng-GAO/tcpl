/**
 * Solution for Exercise 1-18, Chapter 1.
 * Write a program to remove trailing blanks and tabs from
 * each line of input, and to delete entirely lines.
 */

#include <stdio.h>

#define MAX 1000 /* Maximum line length or maximum input lines */
int getlines(char line[], int lim);
void addlines(char to[], char from[], int to_len);

int main()
{
    char line[MAX]; // Current input line
    char result[MAX]; // Result line to be shown
    int result_len = 0;

    while (getlines(line, MAX) > 0) {
        addlines(result, line, result_len+1); 
        // Get the length of result line
        for (result_len = 0; result[result_len] != '\0'; ++result_len);
    }
    printf("%s\n", result);
}

/* getlines: store line from input, return length of the input line */
int getlines(char line[], int lim)
{
    int i, c;

    for (i = 0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        line[i] = c;
    if (c == '\n')
        line[i++] = c;
    line[i] = '\0';

    return i;
}

/* addlines: to remove trailing blanks and tabs from line, and delete
 * entirely blank line, then add to 'to' */
void addlines(char to[], char from[], int to_len)
{
    int i, c;
    int j = to_len - 1;
    int trailing = 1; // Mask of trailing blanks and tabs

    for (i = 0; (c=from[i]) != '\0'; ++i) {
        if (c==' ' || c=='\n' || c=='\t') {
            if (!trailing) {
                to[j++] = c;
                trailing = 1;
            }
        } else {
            to[j++] = c;
            trailing = 0;
        }
    }
    if (c == '\0')
        to[j] = c;
}
    

/**
 * Solution for Exercise 1-23, Chapter 1.
 * Write a program to remove all comments from a C program.
 * Don't forget to handle quoted strings and character
 * constants properly. C comments don't nest.
 */

#include <stdio.h>

#define MAX 1000 /* Maximum input lines and lines' length */
int get_line(char line[], int lim);
int rm_comments(char to[], char from[]);
void add_line(char to[], char line[], int start);

int main()
{
    char line[MAX], new[MAX], result[MAX];
    int start = 0;
    while (get_line(line, MAX) > 0) {
        int new_len = rm_comments(new, line);
        add_line(result, new, start);
        start += new_len;
    }
    printf("%s", result);
    return 0;
}

/* get_line: store input line, return its length */
int get_line(char line[], int lim)
{
    int i, c;

    for (i = 0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        line[i] = c;
    if (c == '\n')
        line[i++] = c;
    line[i] = '\0';
    return i;
}

/* rm_comments: remove comments from "from", then copy it
 * to 'to', return the length of 'to' */
int rm_comments(char to[], char from[])
{
    int start, end; // Start and end location of a comment
    int i, j;

    start = end = 0;
    for (i = 0, j = 0; from[i] != '\0'; ++i, ++j) {
        to[j] = from[i];
        if (from[i] == '/' && from[i+1] == '*')
            start = i;
        if (start >= 0 && from[i] == '/' && from[i-1] == '*')
            end = i;
        if (end > 0) {
            j -= end - start + 1; // Next copy form the 'start' location
            start = end = 0;
        }
    }
    to[j] = '\0';
    return j+1;
}

/* add_line: append line to a string from 'start' location */
void add_line(char to[], char line[], int start)
{
    int i = 0;
    while ((to[start++] = line[i++]) != '\0');
}


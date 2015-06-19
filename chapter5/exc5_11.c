/**
 * Solution to Exercise 5-11, Chapter 5.
 * Modify the program entab and detab (write as exercise in
 * Chapter 1) to accept a list of tab stops as arguments.
 * Use the default tab setting if there are no arguments.
 */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXLINE 1000 /* max length of input line */

void detab(char *r, char *s, int n);
int get_line(char *line, int lim);

int main(int argc, char *argv[])
{
    char line[MAXLINE];
    char rline[MAXLINE];
    int n = 4;

    if (argc == 2 && isdigit(**++argv))
        n = atoi(*argv);

    while (get_line(line, MAXLINE)) {
        detab(rline, line, n);
        printf("%s", rline);
    }

    return 0;
}

/* detab: change each tab to n spaces */
void detab(char *r, char *s, int n)
{
    int i;

    while (*s) {
        if (*s == '\t') {
            i = n;
            while(i--)
                *r++ = ' ';
        } else
            *r++ = *s;
        ++s;
    }
    *r = '\0';
}

/* get_line: get input line, return length of line */
int get_line(char *line, int lim)
{
    int c;
    char *l;

    for (l = line; (c=getchar())!=EOF && c!='\n'; ++l)
        *l = c;
    if (c == '\n')
        *l++ = c;
    *l = '\0';

    return l-line;
}


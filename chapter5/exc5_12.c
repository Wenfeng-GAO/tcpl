/**
 * Solution to Exercise 5-12, Chapter 5.
 * Extend entab to accept the shorthand 'entab -m +n' to mean
 * tab stops every n colums, starting at column m. Choose
 * convenient (for the user) default behavior.
 */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXLINE 1000 /* max length of input line */

void detab(char *r, char *s, int m, int n);
int get_line(char *line, int lim);

int main(int argc, char *argv[])
{
    char line[MAXLINE];
    char rline[MAXLINE];
    int n = 4;
    int m = 1;

    while (--argc) {
        ++argv;
        if (**argv == '-' && isdigit(*++(*argv)))
            m = atoi(*argv);
        if (**argv == '+' && isdigit(*++(*argv)))
            n = atoi(*argv);
    }

    printf("m:%d n:%d\n", m, n);

    while (get_line(line, MAXLINE)) {
        detab(rline, line, m, n);
        printf("%s", rline);
    }

    return 0;
}

/* detab: change each tab to n spaces */
void detab(char *r, char *s, int m, int n)
{
    int i;
    char *p = s + m - 1;

    while (*s) {
        if (s >= p && *s == '\t') {
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


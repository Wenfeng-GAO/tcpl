/**
 * Solution to Exercise 5-13, Chapter 5.
 * Write the program tail, which prints the last n lines of
 * its input. By default, n is set to 10, let us say, but it
 * can be changed by an optional argument so that
 * 'tail -n' prints the last n lines. Write the program so
 * it makes the best use of available storage.
 */

#include <stdio.h>
#include <string.h>

#define MAXLINE 1000 /* max length of an input line */
#define MAXINPUT 10000 /* max input characters */

int get_line(char *line, int lim);

int main()
{
    char line[MAXLINE];
    int l;

    while ((l = get_line(line, MAXLINE)))
        printf("%d:%s", l, line);
    return 0;
}

/* readlines: read lines from input, store it in memory */
void readlines(char *ptr[])
{
    char line[MAXLINE];
    char input[MAXINPUT];
    int l; // length of line
    char *p = input;

    while ((l=get_line(line, MAXLINE)) && p+l <= input+MAXINPUT) {
        strcpy(p, line);
        *ptr++ = p;
        p += l;
    }
}


/* get_line: get input line, retunr length of string */
int get_line(char *line, int lim)
{
    int c;
    char *p;

    for (p=line; (c=getchar())!=EOF && c!='\n'; ++p)
        *p = c;
    if (c == '\n')
        *p++ = c;
    *p = '\0';

    return p - line;
}


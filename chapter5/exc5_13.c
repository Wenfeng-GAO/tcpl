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
#include <ctype.h>
#include <stdlib.h>

#define MAXLINE 1000 /* max length of an input line */
#define MAXINPUT 10000 /* max input characters */
#define MAXLINES 1000 /* max input lines */

int get_line(char *line, int lim);
int readlines(char *ptr[]);

int main(int argc, char *argv[])
{
    char *ptr[MAXLINES];
    int l, i;
    int n = 10; // default tail number

    if (argc == 2 && **++argv == '-' && isdigit(*(*argv+1)))
        n = atoi(*argv+1);
    
    l = readlines(ptr);

    n = (n > l) ? l : n;
    for (i = l-n; i < l; ++i)
        printf("%s", *(ptr+i));

    return 0;
}

/* readlines: read lines from input, store it in memory, return #lines */
int readlines(char *ptr[])
{
    char line[MAXLINE];
    char input[MAXINPUT];
    int l; // length of line
    char **s = ptr;
    char *p = input;

    while ((l = get_line(line, MAXLINE)) 
            && p+l <= input+MAXINPUT && s <= ptr + MAXLINES) {
        strcpy(p, line);
        *s++ = p;
        p += l+1;
    }
    return s - ptr;
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


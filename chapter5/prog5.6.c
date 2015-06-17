#include <stdio.h>
#include <string.h>

void writelines(char *lineptr[], int nlines);
int get_line(char *line, int lim);
char *alloc(int n);

int main()
{
    char line[100];
    char *lines[5];
    int len;
    char *p;

    for (int i = 0; i < 5; ++i) {
        len = get_line(line, 100);
        p = alloc(len);
        strcpy(p, line);
        *(lines+i) = p;
    }

    while (get_line(line, 100))
        printf("%s", line);
    
    return 0;
}


// #define MAXLEN 1000 /* max length of any input line */
// int get_line(char *, int);
// char *alloc(int);
// 
// /* readlines: read input lines */
// int readlines(char *lineptr[], int maxlines)
// {
//     int len, nlines;
//     char *p, line[MAXLEN];
// 
//     nlines = 0;
//     while ((len = getline(line, MAXLEN)) > 0) {
//         if (nlines >= maxlines || p = alloc(len) == NULL)
//             return -1;
//         else {
//             line[len-1] = '\0';
//             stccpy(p, line);
//             lineptr[nlines++] = p;
//         }
//     }
//     return nlines;
// }

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
    int i;

    while (nlines-- > 0)
        printf("%s\n", *lineptr++);
}

/* getline: get an input line, return length */
int get_line(char *line, int lim)
{
    int c;
    char *l = line;

    while (--lim && (c=getchar())!=EOF && c!='\n')
        *l++ = c;
    if (c == '\n')
        *l++ = c;
    *l = '\0';

    return l - line;
}

#define ALLOCSIZE 10000 /* max storage size for input lines */
static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf; /* next free position */

/* alloc: return pointer to the beginning of n characters */
char *alloc(int n)
{
    if (allocbuf + ALLOCSIZE >= allocp + n) {
        allocp += n;
        return allocp - n;
    } else
        return 0;
}

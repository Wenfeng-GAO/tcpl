/**
 * Solution to Exercise 5-7, Chapter 7
 * Rewrite 'readlines' to store lines in an array supplied by 
 * 'main', rather than calling 'alloc' to maintain storage.
 * How much faster is the program?
 */

#include <stdio.h>
#include <string.h>

#define MAXLINES 5000 /* max #lines to be sorted */
char *lineptr[MAXLINES]; /* pointers to text lines */

void writelines(char *lineptr[], int nlines);
int readlines(char *lineptr[], int maxlines, char *bigline, int maxline);
void q_sort(char *v[], int left, int right);

int main()
{
    int n;
    int maxline = 5000;
    char bigline[maxline];

    if ((n = readlines(lineptr, MAXLINES, bigline, maxline)) >= 0) {
        q_sort(lineptr, 0, n-1);
        writelines(lineptr, n);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
}


#define MAXLEN 1000 /* max length of any input line */
int get_line(char *, int);
char *alloc(int);

/* readlines: read input lines, return #readlines */
int readlines(char *lineptr[], int maxlines, char *bigline, int maxline)
{
    int len, nlines;
    char line[MAXLEN];
    static char *p;

    nlines = 0;
    p = bigline;
    while ((len = get_line(line, MAXLEN))) {
        if (nlines >= maxlines || p+len+1 > bigline+maxline)
            return -1;
        else {
            strcpy(p, line);
            lineptr[nlines++] = p;
            p += len+1;
        }
    }
    return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
    int i;

    while (nlines-- > 0)
        printf("%s\n", *lineptr++);
}

/* getline: get an input line, return length of string */
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

// #define ALLOCSIZE 10000 /* max storage size for input lines */
// static char allocbuf[ALLOCSIZE];
// static char *allocp = allocbuf; /* next free position */
// 
// /* alloc: return pointer to the beginning of n characters */
// char *alloc(int n)
// {
//     if (allocbuf + ALLOCSIZE >= allocp + n) {
//         allocp += n;
//         return allocp - n;
//     } else
//         return NULL;
// }

/* q_sort: sort v[left]...v[right] into increasing order */
void q_sort(char *v[], int left, int right)
{
    int i, last;
    void swap(char *v[], int i, int j);

    // Do nothing if array contains fewer than 2 elements
    if (left >= right)
        return;
    swap(v, left, (left+right)/2);
    last = left;
    for (i = left+1; i <= right; ++i) {
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    }
    swap(v, left, last);
    q_sort(v, left, last-1);
    q_sort(v, last+1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j)
{
    char *tmp;

    tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}

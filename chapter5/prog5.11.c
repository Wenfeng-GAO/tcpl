#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 100 /* max input line length */
#define MAXLINES 5000 /* max #lines to be sorted */

#define ALLOCSIZE 10000 /* size of available size for allocbuf */
static char allocbuf[ALLOCSIZE]; /* storage for alloc */
static char *allocp = allocbuf; /* next free position */

void swap(void *v[], int i, int j);
int numcmp(char *s1, char *s2);
void q_sort(void *v[], int left, int right, int (*comp)(void *, void *));
char *alloc(int n);
int get_line(char *s, int lim);
int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int nlines);

int main(int argc, char *argv[])
{
    char *lineptr[MAXLINES];
    int n;

    n = readlines(lineptr, MAXLINES);
    writelines(lineptr, n);
    
    return 0;
}


/* qsort: sort v[left]...v[right] into increasing order */
void q_sort(void *v[], int left, int right, int (*comp)(void *, void *))
{
    int i, last;

    if (left >= right)
        return;
    swap(v, left, (left+right)/2);
    last = left;
    for (i = left+1; i <= right; ++i)
        if ((*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    q_sort(v, left, last-1, comp);
    q_sort(v, last+1, right, comp);
}

/* swap: exchange v[i] and v[j] */
void swap(void *v[], int i, int j)
{
    void *tmp;

    tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}

/* numcmp: compare s1 and s2 numerically */
int numcmp(char *s1, char *s2)
{
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}

/* alloc: return pointer to the beginning of n characters */
char *alloc(int n)
{
    if (allocbuf + ALLOCSIZE >= allocp + n) {
        allocp += n;
        return allocp - n;
    } else
        return NULL; // not enough room
}

/* get_line: get input line, return length of string */
int get_line(char *s, int lim)
{
    int c, i;

    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        *(s+i) = c;
    if (c == '\n') {
        *(s+i) = c;
        ++i;
    }
    *(s+i) = '\0';
    return i;
}

/* readlines: read input lines, return #input lines */
int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLINE];

    nlines = 0;
    while ((len = get_line(line, MAXLINE))) {
        if (nlines > maxlines || !(p = alloc(len+1)))
            return -1;
        else {
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
    int i;

    for (i = 0; i < nlines; ++i)
        printf("%s", lineptr[i]);
}

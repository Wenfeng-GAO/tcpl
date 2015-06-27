#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 5000 /* max #lines to be sorted */

int numcmp(const char *s1, const char *s2);
void q_sort(void *v[], int left, int right, int (*comp)(void *, void *));
int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int nlines);

int main(int argc, char *argv[])
{
    int nlines; // #input lines read
    int numeric = 0; // 1 if numeric sort
    char *lineptr[MAXLINES]; // pointers to text lines

    if (argc > 1 && strcmp(argv[1], "-n") == 0)
        numeric = 1;
    if ((nlines = readlines(lineptr, MAXLINES)) >=0) {
        q_sort((void **)lineptr, 0, nlines-1,
                (int (*)(void*, void*))(numeric ? numcmp : strcmp));
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("input too big to sort\n");
        printf("nlines=%d\n", nlines);
        return 1;
    }
}


void swap(void *v[], int i, int j);

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
int numcmp(const char *s1, const char *s2)
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

#define ALLOCSIZE 20000 /* size of available size for allocbuf */
static char allocbuf[ALLOCSIZE]; /* storage for alloc */
static char *allocp = allocbuf; /* next free position */

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

#define MAXLINE 100 /* max input line length */

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

/**
 * Solution to Exercise 5-16, Chapter 5.
 * Add the -d("directory order") option, which makes comparitions only on letters,
 * numbers and blanks. Make sure it works in conjunction with -f.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLINES 5000 /* max #lines to be sorted */
#define MAXLINE 100 /* max input line length */

void q_sort(void *v[], int left, int right, int r, int (*comp)(void *, void *));
int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int nlines);
int case_ignore_cmp(const char *s1, const char *s2);
int numcmp(const char *s1, const char *s2);

int main(int argc, char *argv[])
{
    char *lineptr[MAXLINES]; // pointers to text lines
    char tmp[MAXLINE];
    int nlines; // #input lines read

    int numeric = 0; // 1 if numeric sort
    int reverse = 0; // 1 if reverse sort
    int fold = 0; // 1 if fold upper and lower case together
    int directory = 0; // 1 if directory order sort

    int c;
    while (--argc) {
        if (**++argv == '-') {
            while (isalpha(c=(*++(*argv)))) {
                switch (c) {
                    case 'n':
                        numeric = 1;
                        break;
                    case 'r':
                        reverse = 1;
                        break;
                    case 'f':
                        fold = 1;
                        break;
                    case 'd':
                        directory = 1;
                        break;
                    default:
                        printf("error input format\n");
                        return 1;
                }
            }
        }
    }
    if (numeric && directory) {
        printf("error input format\n");
        return 1;
    }

    

    return 0;
}



void swap(void *v[], int i, int j);

/* q_sort: sort v[left]...v[right] into increasing order */
void q_sort(void *v[], int left, int right, int r, int (*comp)(void *, void *))
{
    int i, last;

    if (left >= right)
        return;
    swap(v, left, (left+right)/2);
    last = left;
    for (i = left+1; i <= right; ++i) {
        if (!r && (*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
        else if (r && (*comp)(v[i], v[left]) > 0)
            swap(v, ++last, i);
    }
    swap(v, left, last);
    q_sort(v, left, last-1, r,  comp);
    q_sort(v, last+1, right, r,  comp);
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

/* case_ignore_cmp: compare s1 and s2 case insensitive */
int case_ignore_cmp(const char *s1, const char *s2)
{
    char tmp[MAXLINE], c;
    int i;

    for (i = 0; (c=s1[i]) != '\0'; ++i) {
        if (isupper(c))
            c = tolower(c);
        tmp[i] = c;
    }
    tmp[i] = '\0';
    return strcmp(tmp, s2);
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

#include <stdio.h>
#include <ctype.h>
#include <string.h>

struct key {
    char *word;
    int count;
} keytab[] = {
    {"auto", 0},
    {"break", 0},
    {"case", 0},
    {"char", 0},
    {"const", 0},
    {"continue", 0},
    {"default", 0},
    {"while", 0}
};

#define MAXWORD 100
int getword(char *word, int lim);
int binsearch(char *word, struct key tab[], int n);

int main() 
{
    int n;
    char word[MAXWORD];
    int nkeys = 8;

    while (getword(word, MAXWORD) != EOF) {
        if (isalpha(word[0])) {
            if ((n = binsearch(word, keytab, nkeys)) >= 0)
                ++keytab[n].count;
        }
    }
    for (n = 0; n < nkeys; ++n) {
        if (keytab[n].count > 0) 
            printf("%4d %s\n", keytab[n].count, keytab[n].word);
    }
    return 0;
}

/* binsearch: find word in tab[0]...tab[n-1] */
int binsearch(char *word, struct key tab[], int n)
{
    int cond;
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if ((cond = strcmp(word, tab[mid].word)) < 0)
            high = mid - 1;
        else if (cond > 0)
            low = mid + 1;
        else 
            return mid;
    }
    return -1;
}

/* getword: get next word or character from input */
int getword(char *word, int lim)
{
    int c, getch(void);
    void ungetch(int);
    char *w = word;

    while (isspace(c = getch()))
        ;
    if (c != EOF)
        *w++ = c;
    if (!isalpha(c)) {
        *w = '\0';
        return c;
    }
    for ( ; --lim > 0; ++w) {
        if (!isalnum(*w = getch())) {
            ungetch(*w);
            break;
        }
    }
    *w = '\0';
    return word[0];
}

#define MAXBUF 100 /* buf length */
char buf[MAXBUF];
char *bp = buf; /* next free buf position */

/* getch: get character from input or buf */
int getch(void) 
{
    return (bp > buf) ? *(--bp) : getchar();
}

/* ungetch: push character back to buf */
void ungetch(int c)
{
    if (bp < buf + MAXBUF)
        *bp++ = c;
}


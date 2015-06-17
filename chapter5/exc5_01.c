/**
 * Solution to Exercise 5-1, Chapter 5.
 * As written, getint treats a '+' or '-' not followed by a 
 * digit as a valid representation of zero. Fix it to push
 * such a character back on the input.
 */

#include <ctype.h>
#include <stdio.h>

int getch(void);
void ungetch(int);
int getint(int *pn);

int main()
{
    int c;
    while (getint(&c))
        printf("\t%d\n", c);

    return 0;
}

/* getint: get next integer from input into *pn */
int getint(int *pn)
{
    int c, sign;

    while (isspace(c = getch())) 
        ; // Skip white space
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c); // Not a number
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();

    /* Add this part to solve the Exercise */
    if (!isdigit(c)) {
        ungetch(c);
        return 0;
    }
    
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}

#define MAXBUF 100 /* max length of buf array */
int buf[MAXBUF]; /* buffer to store pushed characters */
int *bp = buf; /* a pointer to next free position in buf */

/* getch: get a (possible-pushed) character from stream */
int getch(void)
{
    return (bp > buf) ? *(--bp) : getchar();
}

/* ungetch: push a character back onto stream */
void ungetch(int c)
{
    *bp = c;
    ++bp;
}
        


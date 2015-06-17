/**
 * Solution to Exercise 5-2, Chapter 5.
 * Write getfloat, the floating-point analog of getint.
 * What type doses getfloat return as its function value?
 */

#include <ctype.h>
#include <stdio.h>

int getch(void);
void ungetch(int);
int getfloat(float *);

int main()
{
    float v;

    while(getfloat(&v))
        printf("\t%g\n", v);

    return 0;
}

/* getfloat: get next float number from input into *pn */
int getfloat(float *pn)
{
    int c, sign;
    float pow;

    while (isspace(c = getch())) 
        ; // Skip white space
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c); // Not a number
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();

    if (!isdigit(c)) {
        ungetch(c);
        return 0;
    }
    
    // Collect integer part
    for (*pn = 0.0; isdigit(c); c = getch())
        *pn = 10.0 * *pn + (c - '0');

    if (c == '.') {
        pow = 1.0;
        while (isdigit(c = getch())) {
            pow *= 10.0;
            *pn += (c - '0') / pow;
        }
    }

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
        


/**
 * Part of Polish calculator program 
 */

#include <stdio.h>
#define BUFSIZE 100

static char buf[BUFSIZE]; // Buffer for ungetch()
static int bufp = 0; // Next free position in buf

/* getch: get a (possibly pushed-back) character from stream (or buf) */
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* ungetch: push character back on input (buf) */
void ungetch(int c)
{
    if (bufp < BUFSIZE)
        buf[bufp++] = c;
    else
        printf("ungetch: too many characters\n");
}

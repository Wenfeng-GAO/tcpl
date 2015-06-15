/**
 * Solution to Exercise 4-7, Chapter 4.
 * Write a routine ungets(s) that will push back an entire string
 * onto the input. (just use ungetch)
 */

#include <stdio.h>
#include <string.h>

void ungets(char s[]);
void ungetch(int c);
int getch(void);

int main()
{
    char s[] = "hello, world";
    int c;

    ungets(s);
    while ((c = getch()) != EOF)
        putchar(c);
    
    return 0;
}

/* ungets: push back an entire string onto input */
void ungets(char s[])
{
    int l = strlen(s);

    while (l)
        ungetch(s[--l]);
}

#define MAXBUF 100 /* Max buf size */
char buf[MAXBUF]; /* Buffer to store character re-pushed */
int bp = 0; /* Next free buf position */

/* getch: get a (possible re-pushed) character from stream */
int getch(void)
{
    return (bp > 0) ? buf[--bp] : getchar();
}

/* ungetch: re-push a character back on stream */
void ungetch(int c)
{
    if (bp < MAXBUF)
        buf[bp++] = c;
    else
        printf("error: buf is full\n");
}


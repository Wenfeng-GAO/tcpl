
/**
 * Solution to Exercise 4-9, Chapter 4.
 * Our getch and ungetch do not handle a pushed-back EOF
 * correctly. Decide what their properties ought to be if an
 * EOF is pushed back, then implement your design.
 */

#include <stdio.h>

void ungetch(int c);
int getch();

int main()
{
    int c;

    ungetch('m');
    ungetch(EOF);
    putchar(getch());
        
    return 0;
}

int buf = -1; /* Buffer to store pushback character */

/* ungetch: pushback character onto stream */
void ungetch(int c)
{
    if (c != EOF) {
        if (buf == -1)
            buf = c;
        else
            printf("error: buffer is full.\n");
    }
}

/* getch: get a (possible re-pushed) character from stream */
int getch()
{
    int t;

    if (buf == -1)
        return getchar();
    else {
       t = buf;
       buf = -1;
       return t;
    }
}

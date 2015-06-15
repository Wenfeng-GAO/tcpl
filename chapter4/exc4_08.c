/**
 * Solution to Exercise 4-8, Chapter 4.
 * Suppose that there will never be more than one character of 
 * pushback. Modify getch and ungetch accordingly.
 */

#include <stdio.h>

void ungetch(int c);
int getch();

int main()
{
    int c;

    /*** Test 1
    while ((c = getch()) != EOF) {
        if (c == 'u')
            ungetch('v');
        else if (c == 'U')
            ungetch('V');
        else
            putchar(c);
    }
    */

    ungetch(getch());
    ungetch(getchar());
        
    return 0;
}

int buf = -1; /* Buffer to store pushback character */

/* ungetch: pushback character onto stream */
void ungetch(int c)
{
    if (buf == -1)
        buf = c;
    else
        printf("error: buffer is full.\n");
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

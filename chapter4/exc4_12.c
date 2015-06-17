/**
 * Solution to Exercise 4-12, Chapter 4.
 * Adapt the ideas of 'printd' to write a recursive version of
 * 'itoa'; that is, convert an integer into a string by calling
 * a recursive routine.
 */

#include <stdio.h>

/* itoa: convert an integer into a string */
void itoa(int v, char s[])
{
    static int i = 0;

    if (v < 0) {
        s[i++] = '-';
        v = -v;
    }

    if (v / 10)
        itoa(v/10, s);
    s[i++] = '0' + v % 10;

    s[i] = '\0';
}

int main()
{
    int v = 1234;
    char s[100];

    itoa(v, s);

    printf("%s\n", s);

    return 0;
}

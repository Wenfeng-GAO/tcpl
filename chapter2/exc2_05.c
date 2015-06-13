/**
 * Solution for Exercise 2-5, Chapter 2.
 * Write the function any(s1, s2), which returns the first
 * location in a string 's1' where any character form the 
 * string 's2' occurs, or -1 if 's1' contains no characters
 * from 's2'.
 */

#include <stdio.h>

int in(char s[], int c);
int any(char s1[], char s2[]);

int main()
{
    char s1[] = "hello, world";
    char s2[] = "apple";
    printf("%d\n", any(s1, s2));
    return 0;
}

/* any: return the first location in 's1' where any character
 * from 's2' occurs, or -1 if 's1' contains no characters
 * from 's2'. */
int any(char s1[], char s2[])
{
    int i, r;

    for (i = 0, r = -1; s1[i] != '\0'; ++i) {
        if (in(s2, s1[i])) {
                r = i;
                break;
        }
    }
    return r;
}

/* in: verify whether 'c' is in string 's', returns index+1 
 * if exists, 0 if not. */
int in(char s[], int c)
{
    int i, r;

    for (i = 0, r = 0; s[i] != '\0'; ++i) {
        if (c == s[i])
            r = i + 1;
    }
    return r;
}

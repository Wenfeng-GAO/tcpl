/**
 * Solution to Exercise 5-4, Chapter 5.
 * Write the function strend(s,t), which returns 1 if string
 * t occurs at the end of the string s, and 0 otherwise.
 */

#include <stdio.h>

char strend(char *s, char *t);

int main()
{
    char *s = "hello world";
    char *t = "world";
    if (strend(s, t))
        printf("YES\n");

    return 0;
}

/* strend: return 1 if t occurs at the end of s, 0 otherwise */
char strend(char *s, char *t)
{
    char *l = t;

    while (*s)
        ++s;
    while (*l) {
        ++l;
        --s;
    }
    while (*s == *t) {
        if (*s == '\0')
            return 1;
        ++s;
        ++t;
    }
    return 0;
}
    

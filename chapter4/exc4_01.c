/**
 * Solution to Exercise 4-1, Chapter 4.
 * Write the function strindex(s,t) which returns the position
 * of the rightmost occurrence of t in s, or -1 if there's none.
 */

#include <stdio.h>

#define MAX 100
int strindex(char s[], char t[]);

int main()
{
    char s[] = "an apple a day, yes it is.";
    char t[] = "p";
    printf("%d\n", strindex(s, t));
    return 0;
}

/* strindex: return the position of the rightmost occurence of
 * t in s, or -1 if none */
int strindex(char s[], char t[])
{
    int i, j, k;
    int r = -1;

    for (i = 0; s[i] != '\0'; ++i) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; ++j, ++k)
            ;
        if (k > 0 && t[k] == '\0')  
            r = i;
    }
    return r;
}

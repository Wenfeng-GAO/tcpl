/**
 * Solution for Exercise 2-10, Chapter 2.
 * Rewrite the function 'lower', which converts upper case letters
 * to lower case, with a conditional expression instead of 'if-else'.
 */

#include <stdio.h>

void lower(char s[]);

int main()
{
    char s[] = "Hello World!";
    lower(s);
    printf("%s\n", s);
    return 0;
}

/* lower: convert upper case letters to lower case */
void lower(char s[])
{
    for (int i = 0; s[i] != '\0'; ++i)
        s[i] += (s[i] >= 'A' && s[i] <= 'Z') ? 'a'-'A' : 0;
}

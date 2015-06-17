/**
 * Solution to Exercise 5-3, Chapter 5.
 * Write a pointer version of the function strcat that copies the
 * string t to the end of s.
 */

#include <stdio.h>

void str_cat(char *s, char *t);

int main()
{
    char s[] = "hello";
    char t[] = " world";
    str_cat(s, t);
    printf("%s\n", s);
    return 0;
}

/* strcat: copy the string t to the end of s */
void str_cat(char *s, char *t)
{
    while (*s)
        ++s;
    while ((*s++ = *t++))
        ;
}

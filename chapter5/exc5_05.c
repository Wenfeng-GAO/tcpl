/**
 * Solution to Exercise 5-5, Chapter 5.
 * Write versions of the library functions strncpy, strncat, and
 * strncmp, which operate on at most the first n characters of 
 * their argument strings. For example, strncpy(s,t,n) copies
 * at most n characters of t to s. 
 */

#include <stdio.h>

void str_ncpy(char *s, char *t, int n);
void str_ncat(char *s, char *t, int n);
int str_ncmp(char *s, char *t, int n);

int main()
{
    char s[100] = "hello";
    char *t = "hello world";
    // str_ncpy(s, t, 5);
    // str_ncat(s, t, 5);
    printf("%d\n", str_ncmp(s, t, 6));
    printf("%s\n", s);
    
    return 0;
}

/* strn_cpy: copy at most n characters of t to s */
void str_ncpy(char *s, char *t, int n)
{
    while ((*s++ = *t++) && --n)
        ;
    if (!n)
        *s = '\0';
}

/* str_ncat: add at most n characters of t to the end of s */
void str_ncat(char *s, char *t, int n)
{
    while (*s)
        ++s;
    while ((*s++ = *t++) && --n)
        ;
    if (!n)
        *s = '\0';
}

/* str_ncmp: compare at most n characters of t to s */
int str_ncmp(char *s, char *t, int n)
{
    for ( ; *s == *t && --n; ++s, ++t)
        if (!*s || !n)
            return 0;
    return *s - *t;
}

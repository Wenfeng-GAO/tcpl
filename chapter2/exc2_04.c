/**
 * Solution for Exercise 2-4, Chapter 2.
 * Write an alternative version of squeeze(s1, s2) that delets
 * each character in s1 that matches any character in s2.
 */
#include <stdio.h>

int in(char s[], int c); 
void squeeze(char s1[], char s2[]);

int main()
{
    char s1[] = "hello, world";
    char s2[] = "hellokitty";
    squeeze(s1, s2);
    printf("%s\n", s1);
    return 0;
}

/* squeeze: deletes each character in 's1' that matches any
 * character in 's2' */
void squeeze(char s1[], char s2[])
{
    int i, j;

    for (i = 0, j = 0; s1[i] != '\0'; ++i) {
        if (!in(s2, s1[i])) // each character of s1 not in s2
            s1[j++] = s1[i];
    }
    s1[j] = '\0';
}

/* in: verify if c is in string s, return the index+1 of first
 * apperance of 'c' if exits, return 0 if not */
int in(char s[], int c) 
{
    int i, r;

    for (i = 0, r = 0; s[i] != '\0'; ++i) {
        if (c == s[i]) {
            r = i+1;
            break;
        }
    }
    return r;
}



/**
 * Solution for Exercise 1-19, Chapter 1.
 * Write a function reverse(s) that reverses the character string
 * s. Use it to write a program that reverses its input a line at
 * a time.
 */

#include <stdio.h>

#define MAX 1000 /* Maximum input lines or maximum length of line */
void reverse(char s[]);
int getlines(char line[], int lim);

int main()
{
    char s[MAX];
    while (getlines(s, MAX) > 0) {
        reverse(s);
        printf("%s\n", s);
    }
    return 0;
}

/* reverse: reverse the character string s */
void reverse(char s[])
{
    int i; // Get the length of string
    for (i = 0; s[i] != '\0'; ++i);
    for (int j = 0; j < i/2; ++j) {
        char t = s[j];
        s[j] = s[i-1-j];
        s[i-1-j] = t;
    }
}

/* getlines: store input line, return length of input line */
int getlines(char line[], int lim) 
{
    int i, c;
    for (i = 0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i) 
        line[i] = c;
    if (c == '\n')
        line[i++] = c;
    line[i] = '\0';
    return i;
}




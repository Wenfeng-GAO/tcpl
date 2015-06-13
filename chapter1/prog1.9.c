#include <stdio.h>
#define MAXLINE 1000 /* Maximum input line length */

int getlines(char line[], int maxline);
void copy(char to[], char from[]);

/* Print the longest input line */
int main()
{
    int len; // Current line length
    int max; // Maximum length seen so far
    char line[MAXLINE]; // Current input line
    char longest[MAXLINE]; // Longest line saved here

    max = 0;
    while ((len = getlines(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0) // There was a line
        printf("%s", longest);
    return 0;
}

/* Getline: read a line into s, return length */
int getlines(char s[], int lim)
{
    int c, i;
    
    for (i = 0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

/* Copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    for (int i = 0; (to[i] = from[i]) != '\0'; ++i);
}

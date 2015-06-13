/**
 * Solution for Exercise 2-3, Chapter 2.
 * Write a function htoi(s), which to converts a string of hexadecimal
 * digits(including an optional 0x or 0X) into its equivalent integer
 * value. The allowable digits are 0 through 9, a through f, and A
 * through F.
 */

#include <stdio.h>

#define MAX 1000
int htoi(char s[]);
int get_line(char line[], int lim);

int main()
{
    char line[MAX];
    while (get_line(line, MAX) > 0)
        printf("%d\n", htoi(line));
    return 0;
}

/* htoi: convert a string of hexadecimal digits into its equivalent 
 * integer value */
int htoi(char s[])
{
    int i = 2; // start after '0x'
    int v = 0; // value of string equivalent
    while (s[i] != '\0') {
        char t = '\0';
        if (s[i] >= '0' && s[i] <= '9') 
            t = '0';
        else if (s[i] >= 'a' && s[i] <= 'f')
            t = 'a' - 10;
        else if (s[i] >= 'A' && s[i] <= 'F')
            t = 'A' - 10;
        if (t != '\0')
            v = 16 * v + (s[i] - t);
        ++i;
    }
    return v;
}

/* get_line: store input line, return its length */
int get_line(char line[], int lim)
{
    int i, c;
    for (i = 0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        line[i] = c;
    if (c == '\n')
        line[i++] = c;
    line[i] = '\0';
    return i;
}

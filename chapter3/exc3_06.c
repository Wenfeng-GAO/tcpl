/**
 * Solution to Exercise 3-6, Chapter 3.
 * Write a version of itoa that accepts three arguments instead of
 * two. The third argument is a minimum field width; the converted
 * number must be padded with blanks on the left if necessary to
 * make it wide enough.
 */

#include <stdio.h>
#include <string.h>
    
#define MAX 100
void reverse(char s[]);
void itoa(int n, char s[], int l);

int main()
{
    char s[MAX];
    itoa(-100, s, 4);
    printf("%s\n", s);
    return 0;
}

/* itoa: convert n to characters in s of minimum filed width 'l' */
void itoa(int n, char s[], int l)
{
    int i = 0, sign;

    if ((sign = n) < 0) // Record sign
        n = -n; // Make n positive

    do {
        s[i++] = '0' + n % 10;
    } while ((n /= 10) > 0);

    if (sign < 0)
        s[i++] = '-'; // Add sign '-' if necessary
    
    while (i < l) // Add blanks if necessary
        s[i++] = ' ';
    
    s[i] = '\0';

    reverse(s);
}

/* reverse: reverse a string */
void reverse(char s[])
{
    int i, j;
    for (i = 0, j = strlen(s)-1; i < strlen(s)/2; ++i, --j) {
        int t = s[i];
        s[i] = s[j];
        s[j] = t;
    }
}

/**
 * Solution to Exercise 3-5, Chapter 3.
 * Write the function itob(n,s,b) that converts the integer n into a 
 * base b character representation in the string s. In particular, 
 * itob(n,s,16) formats s as a hexadecimal integer in s.
 */

#include <stdio.h>
#include <string.h>

#define MAX 100

void itob(int n, char s[], int b);
void reverse(char s[]);

int main()
{
    char s[MAX];
    itob(29, s, 16);
    printf("%s\n", s);
    return 0;
}

/* itob: convert the integer n ino a base b character representation in
 * the string 's'. */
void itob(int n, char s[], int b)
{
    if (b == 0 || b > 36)
        return;

    int i = 0, sign;

    if ((sign = n) < 0) // Record sign
        n = -n; // Make n positive

    do {
        int t = n % b;
        if (t < 10)
            s[i++] = '0' + t;
        else
            s[i++] = 'a' + t - 10;
    } while ((n /= b) > 0);

    if (b == 16) { // Add '0x' for 16-bit
        s[i++] = 'x';
        s[i++] = '0';
    }

    if (sign < 0) // Add '-' if necessary
        s[i++] = '-';
    s[i] = '\0';

    reverse(s);
}


/* reverse: reverse a string */
void reverse(char s[])
{
    int i, j, t;
    for (i = 0, j = strlen(s)-1; i < strlen(s)/2; ++i, --j) {
        t = s[i];
        s[i] = s[j];
        s[j] = t;
    }
}

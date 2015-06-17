/**
 * Solution to Exercise 4-13, Chapter 4.
 * Write a recursive version of the function reverse(s), which
 * reverses the string s in place.
 */

#include <string.h>
#include <stdio.h>

/* reverse: reverse the string in place */
void reverse(char s[])
{
    void reverse_r(char [], int, int);
    reverse_r(s, 0, strlen(s)-1);
}

/* reverse_r: reverse the string in place */
void reverse_r(char s[], int i, int j)
{
    int t = s[i];
    s[i] = s[j];
    s[j] = t;
    if (i < j)
        reverse_r(s, ++i, --j);
}

int main()
{
    char s[] = "edcba";
    reverse(s);
    printf("%s\n", s);

    return 0;
}

        

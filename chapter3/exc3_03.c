/**
 * Solution for Exercise 3-3, Chapter 3.
 * Write a function expand(s1,s2) that expands shorthand notations like
 * 'a-z' in the string s1 into the equivalent complete list 'abc...yz'
 * in s2. Allow for letters of either case and digits, and be prepared 
 * to handle cases like 'a-b-c' and 'a-z0-9' and '-a-z'. Arrange that
 * a leading or trailing '-' is taken literally.
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

void expand(char s1[], char s2[]);

int main()
{
    char s1[] = "1-5";
    char s2[MAX];
    expand(s1, s2);
    printf("%s\n", s2);
    return 0;
}

/* expand: expand notations lke 'a-z' in the s1 into the equivalent
 * complete list 'abc...xyz' in s2. */
/* Simple version */
void expand(char s1[], char s2[])
{
    int i, j;

    for (i = 0, j= 0; i < strlen(s1); ++i) {
        if (s1[i+1] == '-'
            && ((isdigit(s1[i]) && isdigit(s1[i+2])) ||
                (isupper(s1[i]) && isupper(s1[i+2])) ||
                (islower(s1[i]) && islower(s1[i+2]))
               )
           ) {
            int t = 0;
            while ((s2[j++] = s1[i] + t++) != s1[i+2])
                ;
            i += 2;
        } else
            s2[j++] = s1[i];
    }
    s2[j] = '\0';
}

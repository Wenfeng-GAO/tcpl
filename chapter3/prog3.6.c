#include <stdio.h>
#include <string.h>

#define MAX 100

void reverse(char s[]);
void itoa(int n, char s[]);

int main()
{
    int n = -10004;
    char s[MAX];
    itoa(n, s);
    printf("%s\n", s);
    return 0;
}

/* itoa: convert n to characters in s */
void itoa(int n, char s[])
{
    int i, sign;

    if ((sign = n) < 0) // Record sign
        n = -n; // Make n positive
    
    // Generate digits in reverse order
    i = 0;
    do {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);

    // Add sign if necessary
    if (sign < 0)
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

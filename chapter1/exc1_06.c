/**
 * Solution to Exercise 1-6, Chapter 1.
 * Verify that the expression getchar() != EOF is 0 or 1.
 */

#include <stdio.h>
int main()
{
    int c;
    char v; // value of getchar() != EOF
    while ((v = ((c = getchar()) != EOF))) {
        putchar(c);
    }
    printf("Value of getchar() != EOF is %d\n", v);

    if (c == EOF) {
        printf("Value of EOF is %d\n", EOF);
    }
    return 0;
}


/**
 * Solution for Exercise 1-14, Chapter 1.
 * Write a program to print a histogram of the frequencies 
 * of different characters in its input.
 */

#include <stdio.h>

#define LIMIT 26
int main()
{
    int c; // Input character
    int alphabet[LIMIT]; // Store frequency of characters

    for (int i = 0; i < LIMIT; ++i)
        alphabet[i] = 0;

    while ((c = getchar()) != EOF) {
        if (c >= 'a' && c <= 'z')
            ++alphabet[c-'a'];
        else if (c >= 'A' && c <= 'Z')
            ++alphabet[c-'A'];
    }

    for (int i = 0; i < LIMIT; ++i)
        printf("%d ", alphabet[i]);
    putchar('\n');

    /* Draw histogram */
    for (int i = 0; i < LIMIT; ++i) {
        printf("%c\t", 'A'+i);
        for (int j = 0; j < alphabet[i]; ++j)
            putchar('=');
        putchar('\n');
    }

    return 0;
}

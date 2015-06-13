/**
 * Solution for Exercise 1-13, Chapter 1.
 * Write a program to print a histogram of the lengths of 
 * words in its input. It is easy to draw the histogram 
 * with the bars horizontal; a vertical orientation is 
 * more challenging.
 */

#include <stdio.h>

int main()
{
    int nw[17]; // Store the number of words whose lengths vary form 0 to 10
    int isFirstSpace; // Flag to split words
    int n; // Use to calculate the number of words
    int c; // Use to store input charactor

    for (int i = 0; i < 17; ++i)
        nw[i] = 0;
    isFirstSpace = n = 0;

    while ((c = getchar()) != EOF) {
        if ( c == ' ' || c == '\t' || c == '\n') {
            if (isFirstSpace) {
                ++nw[n];
                n = 0;
                isFirstSpace = 0;
            }
        } else {
            ++n;
            isFirstSpace = 1;
        }
    }

    /* Draw the horizontal histogram */
    for (int i = 1; i < 17; ++i) {
        printf("Len %2d\tNum %2d\t", i, nw[i]);
        for (int j = 0; j < nw[i]; ++j)
            printf("=");
        printf("\n");
    }

    /* Draw the vertical histogram */
    // First find the maximum number in the array nw[]
    int max = 0;
    for (int i = 0; i < 17; ++i) {
        if (max < nw[i])
            max = nw[i];
    }
    // Then start drawing
    for (int i = max; i > 0; --i) {
        for (int j = 1; j < 17; ++j) {
            if (i <= nw[j])
                printf("  ||\t ");
            else
                printf("    \t ");
        }
        printf("\n");
    }
    for (int i = 1; i < 17; ++i)
        printf("%2d[%2d]  ", i, nw[i]);
    printf("\n");

    return 0;
}
            


    

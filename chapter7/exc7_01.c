/**
 * Solution to Exercise 7-1. Chanpter 7.
 * Write a program that converts upper case to lower or lower case
 * to upper, depending on the name it is invoked with, as found
 * in argv[0].
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int c;

    if (argc == 2) {
        char *s = argv[1];
        while ((c = getchar()) != EOF) {
            if (strcmp(s, "-u") == 0)
                putchar(toupper(c));
            else if (strcmp(s, "-l") == 0)
                putchar(tolower(c));
        }
    }
            
    return 0;
}


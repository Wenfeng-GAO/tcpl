/**
 * Solution to Exercise 7-6, Chapter 7.
 * Write a program to compare two files, printing the first line where they
 * differ.
 */

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
        return 1;
    char s1[100];
    char s2[100];

    FILE *f1 = fopen(argv[1], "r");
    FILE *f2 = fopen(argv[2], "r");
    while (fgets(s1, 100, f1) != NULL && fgets(s2, 100, f2) != NULL) {
        if (strcmp(s1, s2) != 0) {
            fputs(s1, stdout);
            fputs(s2, stdout);
            break;
        }
    }

    return 0;
}

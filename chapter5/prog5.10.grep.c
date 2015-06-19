#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int get_line(char *line, int max);

/* find: print lines that match pattern from 1st arg */
int main(int argc, char *argv[])
{
    char line[MAXLINE];
    int found = 0;

    if (argc != 2)
        printf("Usage: find pattern\n");
    else {
        while (get_line(line, MAXLINE)) {
            if (strstr(line, argv[1])) {
                printf("%s", line);
                ++found;
            }
        }
    }
    return found;
}

/* get_line: get input line, return length of string */
int get_line(char *line, int lim)
{
    int c;
    char *p;
    
    for (p = line; (c=getchar()) != EOF && c != '\n'; ++p)
        *p = c;
    if (c == '\n')
        *p++ = c;
    *p = '\0';

    return p-line;
}
    
        

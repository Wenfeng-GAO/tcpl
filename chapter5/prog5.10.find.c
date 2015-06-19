/* find [-x][-n][-xn] pattern */

#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int get_line(char *line, int lim);

int main(int argc, char *argv[])
{
    char line[MAXLINE];
    long lineno = 0;
    int c, except = 0, number = 0, found = 0;

    while (--argc > 0 && (*++argv)[0] == '-') {
        while ((c = *++argv[0])) {
            switch (c) {
                case 'x':
                    except = 1;
                    break;
                case 'n':
                    number = 1;
                    break;
                default:
                    printf("find: illegal option %c\n", c);
                    argc = 0;
                    found = -1;
                    break;
            }
        }
    }
    if (argc != 1)
        printf("Usage: find -x -n pattern\n");
    else
        while (get_line(line, MAXLINE)) {
            ++lineno;
            if ((strstr(line, *argv) != NULL) != except) {
                if (number)
                    printf("%ld:", lineno);
                printf("%s", line);
                ++found;
            }
        }
    return found;
}

/* get_line: get input line, return length of line */
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

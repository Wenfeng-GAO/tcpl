#include <string.h>

/* trim: remove trailing blanks, tabls, newlines from the end of string */
int trim(char s[])
{
    int n;

    for (n = strlen(s)-1; n >= 0; --n)
        if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
            break;
    s[n+1] = '\0';

    return n;
}

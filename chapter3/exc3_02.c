/**
 * Solution for Exercise 3-2, Chapter 3.
 * Write a function escape(s,t) that converts characters like newline
 * and tab into visible sequences like '\n' and '\t' as it copies the
 * string 't' to 's'. Use a switch. Write a function for the other
 * direction as well, converting escape sequences into the real 
 * characters.
 */

#include <stdio.h>

void escape(char to[], char from[]);
void r_escape(char to[], char from[]);

int main()
{
    char to[100];
    char r_to[100];
    char from[] = "An apple a day,\nmakes the doctor\taway.";
    
    printf("%s\n", from);
    escape(to, from);
    printf("%s\n", to);

    r_escape(r_to, to);
    printf("%s\n", r_to);
    
    return 0;
}

/* escape: converts characters like newline and tab into visible
 * sequences like '\n' and '\t' as it copies the string 'from'
 * to 'to' */
void escape(char to[], char from[])
{
    int i, j;
    for (i = 0, j = 0; from[i] != '\0'; ++i) {
        switch(from[i]) {
            case '\n':
                to[j++] = '\\';
                to[j++] = 'n';
                break;
            case '\t':
                to[j++] = '\\';
                to[j++] = 't';
                break;
            default:
                to[j++] = from[i];
                break;
        }
    }
    to[j] = '\0';
}

/* r_escape: the reverse of escape function */
void r_escape(char to[], char from[])
{
    int i, j;
    for (i = 0, j = 0; from[i] != '\0'; ++i) {
        if (from[i] == '\\' && from[i+1] == 'n') {
            to[j++] = '\n';
            ++i;
        } else if (from[i] == '\\' && from[i+1] == 't') {
            to[j++] = '\t';
            ++i;
        } else 
            to[j++] = from[i];
    }
    to[j] = '\0';
}

#include <ctype.h>
#include <stdio.h>

#define MAX 100

double atof(char s[]);
int get_line(char line[], int lim);

/* rudimentary calculator */
int main()
{
    char line[MAX];
    double sum = 0;
    //double atof(char s[]);

    while (get_line(line, MAX) > 0) {
        printf("\t%g\n", sum += atof(line));
    }
    return 0;
}

/* atof: convert string s to double */
double atof(char s[])
{
    double val, power;
    int i, sign;

    for (i = 0; isspace(s[i]); ++i) // Skip white space
            ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        ++i;
    for (val = 0.0; isdigit(s[i]); ++i) 
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        ++i;
    for (power = 1.0; isdigit(s[i]); ++i) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
    return sign * val / power;
}

int get_line(char line[], int lim)
{
    int i, c;

    i = 0;
    while (--lim>0 && (c=getchar())!=EOF && c!='\n')
        line[i++] = c;
    if (c == '\n')
        line[i++] = c;
    line[i] = '\0';
    return i;
}

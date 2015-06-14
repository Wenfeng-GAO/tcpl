/**
 * Solution to Exercise 4-2, Chapter 4.
 * Extend atof to handle scientific notation of the form '123.45e-6'
 * where a floating-point number may be followed by 'e' or 'E' and
 * an optionally signed exponent.
 */

#include <stdio.h>
#include <ctype.h>

double atof(char s[]);

int main()
{
    char s[] = "  -123.45e-6";
    printf("%g\n", atof(s));
    return 0;
}

/* atof: return equivalent double value of string */
double atof(char s[])
{
    int i, j, sign, esign;
    double val, power, eval, epower;

    for (i = 0; isspace(s[i]); ++i) // Skip space
        ;

    sign = (s[i] == '-') ? -1 : 1; // Record sign

    if (s[i] == '+' || s[i] == '-') // Skip sign notation
        ++i;

    for (val = 0.0; isdigit(s[i]); ++i) 
        val = val * 10.0 + (s[i] - '0');

    if (s[i] == '.') // Skip the '.'
        ++i;

    for (power = 1.0; isdigit(s[i]); ++i) {
        power *= 10.0;
        val = val * 10.0 + (s[i] - '0');
    }

    if (s[i] == 'e' || s[i] == 'E') // Skip 'e' notation
        ++i;

    esign = (s[i] == '-') ? -1 : 1; // Record 'e' sign

    if (s[i] == '-') // Skip '-' notation after 'e'
        ++i;

    for (eval = 0.0; isdigit(s[i]); ++i)
        eval = eval * 10.0 + (s[i] - '0');

    val = sign * val / power;

    for (j = 0, epower = 1.0; j < eval; ++j) 
        epower *= 10;

    return esign == 1 ? val*epower : val/epower;

}



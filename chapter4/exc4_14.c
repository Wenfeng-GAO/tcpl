/**
 * Solution to Exercise 4-14, Chapter 4.
 * Define a macro swap(t,x,y) that interchanges two
 * arguments of type t. (Block structure will help.)
 */

#include <stdio.h>

#define swap(t, x, y) {t temp = x; x = y; y = temp;}
#define dprint(x) printf(#x "= %g\n", x)

int main()
{
    double x = 1.9, y = 2;
    dprint(x);
    dprint(y);
    swap(double, x, y);
    dprint(x);
    dprint(y);

    return 0;
}

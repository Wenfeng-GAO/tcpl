/**
 * Part of Polish calculator program
 */

#include <stdio.h>

#define MAXVAL 100 /* Maximum depth of val stack */

static int sp = 0; // Next free stack position
static double val[MAXVAL]; // Value stack

/* push: push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

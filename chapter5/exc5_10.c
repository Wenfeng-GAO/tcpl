/**
 * Solution to Exercise 5-10, Chapter 5.
 * Write the program expr, which evaluates a reverse Polish 
 * expression from the command line, where each operator or
 * operand is a separate argument. For example, 
 * 'expr 2 3 4 + * ' evaluates '2*(3+4)'.
 */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void push(int n);
int pop(void);

/* expr: evaluate a reverse Polish expression from command line */
int main(int argc, char *argv[])
{
    int err = 0;
    int c, op1, op2;

    printf("Usage example:\n"
            "./a.out 2 3 4 + /\n./a.out 2 3 4 + \\*\n");
    printf("*******************\n\n");

    while (--argc) {
        c = **++argv;
        if (isdigit(c))
            push(atoi(*argv));
        else {
            switch (c) {
                case '+':
                    push(pop() + pop());
                    break;
                case '*':
                    push(pop() * pop());
                    break;
                case '-':
                    op2 = pop();
                    op1 = pop();
                    push(op1 - op2);
                    break;
                case '/':
                    op2 = pop();
                    op1 = pop();
                    if (op2)
                        push(op1 / op2);
                    else {
                        printf("error: zero divisor\n");
                        err = 1;
                    }
                    break;
                default:
                    printf("illegal format: %d\n", c);
                    err = 1;
                    return -1;
            }
        }
    }
    if (!err)
        printf("\t%d\n", pop());
    return 0;
}

#define MAXSTK 1000 /* stack depth */
int stk[MAXSTK]; /* stack to store numbers */
int *stkptr = stk; /* next free position of stack */

/* push: push number onto the top of stack */
void push(int n)
{
    if (stkptr - stk > MAXSTK)
        printf("error: stack is full, can't push\n");
    else
        *stkptr++ = n;
}

/* pop: pop and return from top of stack */
int pop(void)
{
    if (stkptr > stk)
        return *--stkptr;
    else {
        printf("error: stack is empty, can't pop\n");
        return 0;
    }
}

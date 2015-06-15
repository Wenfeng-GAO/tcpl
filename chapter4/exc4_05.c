/**
 * Solution to Exercise 4-5, Chapter 4.
 * Add access to library functions like sin, exp, and pow.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUMBER '0' /* Signal that a number was found */
#define MAXOP 100 /* Max size of operator or operand */

int getop(char s[]);
void push(double v);
double pop(void);
void clrstk(void);
void dpc(void);
void swap2(void);
void print_top(void);

int ERROR = 0; /* Error signal */
int CLEAR = 0; /* Clear stack signal */

/* reverser Polish calculator, extended version */
int main()
{
    char s[MAXOP];
    int c;
    double op1, op2, t;

    printf("Input:\n'C' to clear stack;\n'T' to show the top "
            "element of stack;\n'D' to duplicate the top "
            "element of stack and push it on stack;\n"
            "'S' to swap the top 2 elements out of stack.\n");
    printf("Use 's' for 'sin'; 'e' for 'exp' and 'p'"
            " for power.\n");

    while ((c = getop(s)) != EOF) {
        switch (c) {
            case NUMBER:
                push(atof(s));
                break;
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
                if (op2 != 0.0)
                    push(op1 / op2);
                else {
                    printf("No zero divisor.\n");
                    ERROR = 1;
                }
                break;
            case '%':
                op2 = pop();
                op1 = pop();
                if ((op2 - (int)op2) || (op1 - (int)op1)) {
                    printf("Only integers can do modulus\n");
                    ERROR = 1;
                } else if (op2 == 0.0) {
                    printf("No zero divisor.\n");
                    ERROR = 1;
                } else
                    push((int)op1 % (int)op2);
                break;
            case 'C':
                clrstk();
                break;
            case 'T':
                print_top();
                break;
            case 'D':
                dpc();
                break;
            case 'S':
                swap2();
                break;
            case 's':
                push(sin(pop()));
                break;
            case 'e':
                push(exp(pop()));
                break;
            case 'p':
                op2 = pop();
                op1 = pop();
                if ((op1 == 0.0 && op2 <= 0.0) || 
                        (op1 < 0.0 && op2 - (int)op2 > 0.0)) {
                    printf("Wrong range.\n");
                    ERROR = 1;
                } else
                    push(pow(op1, op2));
                break;
            case '\n':
                if (!ERROR)
                    printf("\t%.8g\n", pop());
                else 
                    ERROR = 0;
                break;
            default:
                printf("Error operations.\n");
                break;
        }
    }
    return 0;
}

#define MAXSTACK 100 /* Depth of stack */
double stack[MAXSTACK];
int sp = 0; /* Next free stack position */

/* push: push value onto the stack */
void push(double v)
{
    if (sp < MAXSTACK)
        stack[sp++] = v;
    else {
        printf("Error push: stack is full.\n");
        ERROR = 1;
    }
}

/* pop: pop and return value from the top of the stack */
double pop(void)
{
    if (sp > 0)
        return stack[--sp];
    else {
        printf("Error pop: stack is empty.\n");
        ERROR = 1;
        return 0.0;
    }
}

/* print_top: print the top element of stack without pop */
void print_top(void)
{
    if (sp > 0)
        printf("Top element of stack: %.8g\n", stack[sp-1]);
    else 
        printf("Error: stack empty.\n");
    ERROR = 1;
}

/* clrstk: clear the stack */
void clrstk(void)
{
    sp = 0;
    ERROR = 1;
    printf("Stack cleared\n");
}

/* dpc: duplicate the top element of stack and push it on */
void dpc(void)
{
    if (sp > 0) {
        stack[sp] = stack[sp-1];
        ++sp;
        printf("The top element of stack has been duplicated"
            " and pushed on.\n");
    } else
        printf("Error: stack empty.\n");
    ERROR = 1;
}

/* swap2: swap the top two elements of stack */
void swap2(void)
{
    if (sp > 1) 
        sp -= 2;
    else if (sp > 0)
        --sp;
    printf("The top two elements of stack has been swaped.\n");
    ERROR = 1;
}

#include <ctype.h>
char getch(void);
void ungetch(int c);

/* getop: return operators or get numbers in the array */
int getop(char s[])
{
    int c, i = 0;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ; // Skip white blanks

    if (!isdigit(c) && c != '.') { // Not a number
        if(c == '+' || c == '-') {
            if (!isdigit(s[++i] = c = getch())) {
                ungetch(c);
                s[1] = '\0';
                return s[0];
            }
        } else {
            s[1] = '\0'; 
            return c;
        }
    }

    if (isdigit(c)) // Collect integer part
        while (isdigit(s[++i] = c = getch()))
                ;

    if (c == '.') // Collect fraction part
        while (isdigit(s[++i] = c = getch()))
            ;

    s[i] = '\0';

    if (c != EOF)
        ungetch(c);

    return NUMBER;
}

#define MAXBUF 100 /* Buf storage */
char buf[MAXBUF]; // Buf to store ungetch() characters
int bufp = 0; // Next free buff position

/* getch: get a (possible pushed-back ) character from stream or buf */
char getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* ungetch: place the character back to buf */
void ungetch(int c)
{
    if (bufp < MAXBUF)
        buf[bufp++] = c;
    else {
        printf("Error ungetch: buf is full.\n");
        ERROR = 1;
    }
}


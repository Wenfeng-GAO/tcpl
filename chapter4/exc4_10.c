/**
 * Solution to Exercise 4-10, Chapter 4.
 * An alternate organization uses getline to read an entire
 * input line; this makes getch and ungetch unnecessary.
 * Revise the calculator to use this approach.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100 /* Max size of operand or operator */
#define NUMBER '0' /* Signal that a number was found */

void push(double);
double pop(void);

#define MAXLINE 100 /* Maximum input line length */
int get_line(char line[], int lim);
char line[MAXLINE];

/* reverse Polish calculator */
int main()
{
    /*
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s); 
                break;
        }
    }
    */
    while (get_line(line, MAXLINE))
        printf("%s", line);

    return 0;

}



#define MAXVAL 100 /* Maximum depth of val stack */

int sp = 0; // Next free stack position
double val[MAXVAL]; // Value stack

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




/* get_line: get an entire line from input stream */
int get_line(char line[], int lim) 
{
    int i = 0, c;

    while (--lim && (c = getchar()) != EOF && c != '\n')
        line[i++] = c;
    if (c == '\n')
        line[i++] = c;
    line[i] = '\0';

    return i;
}


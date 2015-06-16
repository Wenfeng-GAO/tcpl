/**
 * Solution to Exercise 4-10, Chapter 4.
 * An alternate organization uses getline to read an entire
 * input line; this makes getch and ungetch unnecessary.
 * Revise the calculator to use this approach.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define NUMBER '0' /* number signal */
#define MAXLINE 100 /* max length of an input line */
#define MAXVAL 100 /* max length of val array */
#define MAXSTACK 100 /* depth of stack */

char line[MAXLINE]; /* input line */
int lp; /* next unscanned position */
double stk[MAXSTACK]; /* stack to store pushed numbers */
int sp; /* next free stack position */

int get_line(char line[], int lim);
void noblanks(void);
void append(char s[], int c);
void storenumber(char v[]);
int getop(char val[]);
double pop(void);
void push(double v);

int main()
{
    char val[MAXVAL];
    int c;
    double op1, op2;

    while (get_line(line, MAXLINE)) {
        lp = 0;
        while (lp < strlen(line)) {
            val[0] = '\0';
            switch (getop(val)) {
                case NUMBER:
                    push(atof(val));
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
                    else
                        printf(" zero denominator\n");
                    break;
                case '\n':
                    printf("\t=%.6g\n", pop());
                    break;
            }
        }
    }

    return 0;
}

/* pop: pop and return value from top of stack */
double pop(void)
{
    if (sp > 0)
        return stk[--sp];
    else
        printf("error: stack is empty, can't pop\n");
    return 0.0;
}

/* push: push value on top of stack */
void push(double v)
{
    if (sp < MAXSTACK)
        stk[sp++] = v;
    else
        printf("error: stack is full, can't push\n");
}

/* noblanks: skip white blanks */
void noblanks(void)
{
    while (line[lp] == ' ' || line[lp] == '\t')
        ++lp;
}

/* getop: return operator (or other non number) character */
int getop(char val[])
{
    int c;

    noblanks();

    if (!isdigit(c=line[lp]) && c != '.' && c != '-') {
        ++lp;
        return c;
    }

    storenumber(val);

    if (c == '.' || c == '-') {
        if (!isdigit(line[++lp])) {
            return c;
        } else {
            append(val, c);
            storenumber(val);
        }
    }
    
    return NUMBER;
}

/* append: append a character to the end of a string */
void append(char s[], int c)
{
    int l = strlen(s);
    s[l] = c;
    s[l+1] = '\0';
}

/* storenumber: to store number in the array */
void storenumber(char v[])
{
    while (isdigit(line[lp]))  {
        append(v, line[lp++]);
    }
}

/* get_line: get entire line from input stream, return length */
int get_line(char line[], int lim)
{
    int c, i;

    for (i = 0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        line[i] = c;
    if (c == '\n')
        line[i++] = c;
    line[i] = '\0';

    return i;
}


/**
 * Head file of Polish calculator program.
 */

#define NUMBER '0' /* Signal that a number was found */

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

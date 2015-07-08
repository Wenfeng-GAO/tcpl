#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXWORD 100

/* the tree node */
struct tnode {
    char *word;          // pointer to the text
    int count;           // number of occurrences
    struct tnode *left;  // left child 
    struct tnode *right; // right child
};
struct tnode *addtree(struct tnode *p, char *w);
void treeprint(struct tnode *p);
int getword(char *word, int lim);

int main()
{
    struct tnode *root;
    char word[MAXWORD];

    root = NULL;
    while (getword(word, MAXWORD) != EOF) {
        if (isalpha(*word))
            root = addtree(root, word);
    }
    treeprint(root);
    return 0;
}

struct tnode *talloc(void);
char *str_dup(char *s);

/* addtree: add a node with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w)
{
    int cond;

    if (p == NULL) {  // a new word has arrived
        p = talloc(); // make a new node
        p->word = str_dup(w);
        p->count = 1;
        p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0) {
        p->count++;   // repeated word
    } else if (cond < 0) {
        p->left = addtree(p->left, w);
    } else {
        p->right = addtree(p->right, w);
    }
    return p;
}

/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p)
{
    if (p != NULL) {
        treeprint(p->left);
        printf("%4d %s\n", p->count, p->word);
        treeprint(p->right);
    }
}

#include <stdlib.h>

/* talloc: make a tnode */
struct tnode *talloc(void)
{
    return (struct tnode *) malloc(sizeof(struct tnode));
}

/* str_dup: copy the string given into a safe place */
char *str_dup(char *s)
{
    char *p;

    p = (char *) malloc(strlen(s)+1); // +1 for '\0'
    if (p != NULL)
        strcpy(p, s);
    return p;
}

/* getword: get next word or character from input */
int getword(char *word, int lim)
{
    int c, getch(void);
    void ungetch(int);
    char *w = word;

    while (isspace(c = getch()))
        ;
    if (c != EOF)
        *w++ = c;
    if (!isalpha(c)) {
        *w = '\0';
        return c;
    }
    while (--lim) {
        if (!isalnum(*w = getch())) {
            ungetch(*w);
            break;
        }
        ++w;
    }
    *w = '\0';
    return *word;
}

#define MAXBUF 100 /* buf length */
int buf[MAXBUF];
int *bp = buf; /* next free buf position */

/* getch: get character from input or buf */
int getch(void)
{
    return (bp > buf) ? *(--bp) : getchar();
}

/* ungetch: push character back to buf */
void ungetch(int c)
{
    if (bp < buf + MAXBUF)
        *bp++ = c;
}


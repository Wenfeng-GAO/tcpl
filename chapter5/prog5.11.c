#include <stdio.h>
#include <stdlib.h>

void swap(void *v[], int i, int j);
int numcmp(char *s1, char *s2);

int main(int argc, char *argv[])
{
    char c[] = "2";
    char *f = "12";
    
    printf("%d\n", numcmp(c, f));

    return 0;

}

/* swap: exchange v[i] and v[j] */
void swap(void *v[], int i, int j)
{
    void *tmp;

    tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}

/* numcmp: compare s1 and s2 numerically */
int numcmp(char *s1, char *s2)
{
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}

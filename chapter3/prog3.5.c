# include <ctype.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

#define MAX 200000
void reverse(char s[]);
//int atoi(char s[]);
void shellsort(int v[], int n);
void inssort(int v[], int n);
void inssort(int v[], int n);

int main()
{
    /*
    char s[6] = "321- ";
    reverse(s);
    printf("%s\n", s);

    printf("%d\n", atoi(s));
    */

    int v[MAX];
    srand(time(0));
    for (int i = 0; i < MAX; ++i) 
        v[i] = rand();
    //shellsort(v, MAX);
    inssort(v, MAX);
    return 0;
}

/* inssort: insertion sort */
void inssort(int v[], int n)
{
    int i, j, key;
    for (i = 1; i < n; ++i) {
        key = v[i];
        for (j = i-1; key < v[j] && j >=0; --j) 
            v[j+1] = v[j];
        v[j+1] = key;
    }
}

/* atoi: convert s to integer; version 2 */
int a_to_i(char s[])
{
    int i, n, sign;

    for (i = 0; isspace(s[i]); ++i)
        ; // Skip white space
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        ++i; // Skip sign
    for (n = 0; isdigit(s[i]); ++i)
        n = 10 * n + (s[i] - '0');
    return sign * n;
}

/* shellsort: sort v[0]...v[n-1] into increasing order */
void shellsort(int v[], int n)
{
    int gap, i, j, temp;

    for (gap = n/2; gap > 0; gap/=2) {
        for (i = gap; i < n; ++i) {
            for (j = i-gap; j >= 0 && v[j] > v[j+gap]; j -= gap) {
                temp = v[j];
                v[j] = v[j+gap];
                v[j+gap] = temp;
            }
        }
    }
}

/* reverse: reverse string s in place */
void reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s)-1; i < j; ++i, --j) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

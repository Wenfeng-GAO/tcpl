/**
 * Solution for Exercise 3-1, Chapter 3.
 * Our binary search makes two tests inside the loop, when one 
 * would suffice (at the price of more tests outside). Write a
 * version with only one test inside the loop and measure the
 * difference in run-time.
 */

#include <stdio.h>
#include <limits.h>

#define MAX 1000000 /* Maximum array length */

int binsearch(int x, int v[], int n);
int bsearch(int x, int v[], int n);
void get_num(int v[], int n);

int main()
{
    int v[MAX];
    
    get_num(v, MAX);
    for (int i = 0; i < 10000; ++i)
        //binsearch(500000, v, MAX);
        bsearch(500000, v, MAX);
    return 0;
}

/* bsearch: binary search */
int bsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

/* binsearch: binary search */
int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low < high) {
        mid = (low + high) / 2;
        if (x <= v[mid])
            high = mid;
        else
            low = mid + 1;
    }
    return x == v[high] ? high : -1;
}

/* get_num: generate numbers to test */
void get_num(int v[], int n)
{
    for (int i = 0; i < n; ++i)
        v[i] = i;
}


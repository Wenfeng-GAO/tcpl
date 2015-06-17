#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* q_sort: sort v[left]...v[right] into increasing order 
 * always set the middle element of unsorted array as partition
 */
void q_sort(int v[], int left, int right)
{
    int i, last;
    void swap(int v[], int i, int j);

    // Do nothing if array contains fewer than 2 elements 
    if (left >= right)
        return;

    // Move partition elem to the left
    swap (v, left, (left+right)/2); 
    
    last = left;
    for (i = left + 1; i <= right; ++i) {
        if (v[i] < v[left])
            swap(v, i, ++last);
    }

    // Restore partition element to make it in sorted position
    swap(v, left, last);

    q_sort(v, left, last-1);
    q_sort(v, last+1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(int v[], int i, int j)
{
    int t;
    t = v[i];
    v[i] = v[j];
    v[j] = t;
}

/* parray: print array */
void parray(int v[], int l)
{
    for (int i = 0; i < l; ++i)
        printf("%d ", v[i]);
    printf("\n");
}

int main()
{
    int v[1000];

    srand(time(0));
    for (int i = 0; i < 1000; ++i)
        v[i] = rand() % 1000;

    q_sort(v, 0, 999);

    parray(v, 1000);




    return 0;
}

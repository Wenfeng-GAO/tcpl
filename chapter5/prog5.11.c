#include <stdio.h>

void swap(void *v[], int i, int j);

int main(int argc, char *argv[])
{
    int t[] = {1, 2, 3};
    int *v[3];
    for (int i = 0; i < 3; ++i)
        *(v+i) = &t[i];
    swap((void *)v, 0, 2);
    for (int i = 0; i < 3; ++i)
        printf("%d ", **(v+i));
    printf("\n");
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

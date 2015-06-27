/**
 * Generate random numbers for testing prog.5.11.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i;

    srand(time(0));
    for (i = 0; i < 3000; ++i) 
        printf("%d\n", rand()%3000);

    return 0;
}
    


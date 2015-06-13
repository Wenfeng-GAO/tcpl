/**
 * Solution for Exercise 2-1, Chapter 2.
 * Write a program to determine the ranges of char, short, int, and
 * long variables, both signed and unsigned, by printing appropriate
 * values from standard headers and by direct computation.
 */

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
    printf("The range of:\n");

    printf("unsigned char\t%d ~ %d\n", 0, UCHAR_MAX);
    printf("signed char  \t%d ~ %d\n", SCHAR_MIN, SCHAR_MAX);

    printf("unsigned short\t%u ~ %u\n", 0, USHRT_MAX);
    printf("signed short  \t%d ~ %d\n", SHRT_MIN, SHRT_MAX);
    
    printf("unsigned int\t%u ~ %u\n", 0, UINT_MAX);
    printf("signed int  \t%d ~ %d\n", INT_MIN, INT_MAX);

    printf("unsigned long\t%u ~ %lu\n", 0, ULONG_MAX);
    printf("signed long  \t%ld ~ %ld\n", LONG_MIN, LONG_MAX);
    

    printf("The range(precise) of flaot and double:\n");

    printf("float \t%f | %f\n", FLT_MIN, FLT_MAX);
    printf("double\t%f | %f\n", DBL_MIN, DBL_MAX);
    
    
    
    
    return 0;
}




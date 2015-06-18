#include <stdio.h>

char *month_name(int n);

int main()
{
    for (int i = 1; i <= 12; ++i)
        printf("%s\n", month_name(i));

    return 0;
}

/* month_name: return name of n-th month */
char *month_name(int n)
{
    static char *name[] = {
        "Illegal month",
        "january", "February", "March",
        "April", "May", "June",
        "July", "August", "September",
        "October", "November", "December"
    };

    return (n<1 || n>12) ? name[0] : name[n];
}

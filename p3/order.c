#include <stdio.h>

static void ascending2(int (*a), int (*b))
{
    if (*a > *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
}

static void ascending3(int (*a), int(*b), int(*c))
{
   if ((*a > *b)&&( 
}

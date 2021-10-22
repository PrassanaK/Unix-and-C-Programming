#include <stdio.h>
#include <math.h>

int calcPower(void)
{
    static int val;
    val = val * 2;
    printf("%d", &val);   
       
}


int main(void)
{
    return 0;
}

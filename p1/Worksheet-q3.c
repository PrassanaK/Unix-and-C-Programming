#include <stdio.h>

int calcFactorial(int n)
{
    int i, fact=1;

    for (i=1; i<=n; i++)
    {
        fact = (fact * i);
    }
    return fact;
}

int main(void)
{
    int n, factorial;
 
    printf("Enter a number: ");
    scanf("%d",&n);

    while(n>=0)
    {    
        factorial = calcFactorial(n);
        printf("%d", factorial);

        printf("Enter a number: ");
        scanf("%d", &n);
    }
    return 0;
}

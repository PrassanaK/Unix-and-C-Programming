#include <stdio.h>

int main(void)
{
    int a, b;
    printf("Enter values: ");
    scanf("%d %d",&a, &b);

    if (a%b==0)
        printf("Divisible. \n");
    else
        printf("Not Dividible.\n");    

    return 0;

}

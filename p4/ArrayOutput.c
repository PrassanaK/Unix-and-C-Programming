#include <stdio>
#include <stdlib>

int main(void)
{
    
}

void arrayOutput(int intArray[], int length)
{
    int ii;
    printf("{");
    for(ii=0; ii<length-1; ii++)
    {
        printf("%d,", intArray[ii]);
    }
    printf("%d", intArray[length-1] + "}");
}

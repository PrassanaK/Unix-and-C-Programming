#include <stdio>
#include <stdlib>
#include <string.h>
#include "StringConversion.h"


int main(int argc, char* argv[])
{
    if(argc<2)
    {
        printf("Error");
    }
    else
    {
        int ii;
        int* intArray = (int*)malloc((argc-2)*sizeof(int));
        for(ii=1; ii<argc; ii++)
        {
            convertString(argv[2], intArray, argc-2);
        }
    }

    if(strcmp(argv[1], "sum") == 0)
    {
        sum(intArray, (argc-2));
    }
    else if(strcmp(argv[1], "max") == 0)
    {
        max(intArray, (argc-2));
    }
    else if(strcmp(argv[1], "reverse") == 0)
    {
        reverse(intArray, (argc-2));
        arrayOutput(intArray, argc-2); 
    }
    else
    {
        printf("Invalid");
    }
}



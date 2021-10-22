#include <stdio.h>
#include <stdlib.h>
#include "randomarray.h"

int main(int argc, char* argv[])
{
    if((argc!=4))
    {
        printf("Invalid number of arguments");
    }
    else
    {
        int i, ii, jj, p;
        double **arr;
        FILE* fo = fopen(argv[1], "w");
        int argv2, argv3;
         
        argv2 = atoi(argv[2]);
        argv3 = atoi(argv[3]);
        fprintf(fo, "%d %d", argv2, argv3);
        
        arr = (double **)malloc(argv2*sizeof(double*));

        for(i=0; i<argv2; i++)
        {
            arr[i] = (double*)malloc(argv3*sizeof(double));
        } 

        randomArray(arr, argv2, argv3, 5);

        for(ii=0; ii<argv2; ii++)
        { 
            for(jj=0; jj<argv3; jj++)
            {
                fprintf(fo, "%f ", arr[ii][jj]);
            }
        }
 
        fclose(fo);
        for(p=0; p<argv2; p++)
        {
            free(arr[p]);
        }
        free(arr);
    }
    return 0;
}

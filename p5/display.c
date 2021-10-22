#include <stdio.h>
#include <stdlib.h>
#include "plot.h"

int main(int argc, char* argv[])
{
    if(argc>2)
    {
        printf("Invalid number of comand line arguments\n");
    }
    else
    {
        int i, ii, jj, p, rows, columns;
        double **arr;
        FILE* fi = fopen(argv[1], "r");
        fscanf(fi, "%d %d", &rows, &columns);

        arr = (double **)malloc(rows*sizeof(double*));
        
        for(i=0; i<rows; i++)
        {
            arr[i] = (double*)malloc(columns*sizeof(double));
        }

        for(ii=0; ii<rows; ii++)
        {
            for(jj=0; jj<columns; jj++)
            {
                fscanf(fi, "%lf ", &arr[ii][jj]);
            }
        }

        plot(arr, rows, columns);
        fclose(fi);

        for(p=0; p<rows; p++)
        {
            free(arr[p]);
        }
        free(arr);
    }    
    return 0;
}

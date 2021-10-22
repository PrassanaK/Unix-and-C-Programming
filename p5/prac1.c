#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
        if(argc!=3)
        {
            printf("Invalid number of command line arguements/n");
        }
        else
        { 
            FILE* fi = fopen(argv[1], "r");
            if(fi==NULL)
            {
                printf("File is empty or didn't open properly");
            } 
            else
            {
                FILE* fo = fopen(argv[2], "w");
                if (fo==NULL)
                {
                    perror("");
                }
                else
                {
                    int ch;

                    do
                    {
                        ch=fgetc(fi);
                        fputc(ch, fo); 
                    }while(ch!=EOF);
                }
                fclose(fo);
            }
            fclose(fi);
        }
        return 0;
}

#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    if (argc>2)
    {
       printf("Invalid number of command line arguements");
    }
    else
    {
        FILE* f = fopen(argv[1], "r");
        if(f==NULL)
        {
            printf("File is empty or didn't open properly");
        }
        else
        {
            int day, hour, min, sec, secsSinceMidnight;
            char* month = NULL;
            char* process=NULL;
            char str[500];
            char* ret = NULL;
            fscanf(f, "%s %d %d:%d:%d %s", month, &day, &hour, &min, &sec, process);
            
            secsSinceMidnight = ((hour/3600)+(min/60)+sec);

            if(fgets(str, 500, f)==NULL)
            {
                printf("Error");
            } 
            else
            {
                fgets(str,500,f);
                ret = strstr(str, "fail");
                if(ret!=NULL)
                {
                    printf("Substring is %s\n", ret);
                }
                else
                {
                    printf("fail is not present in the full string\n");
                }
                printf("%d\n", secsSinceMidnight);
            }
        }
        fclose(f);
    }
    return 0;
}

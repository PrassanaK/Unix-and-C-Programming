#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prac1.h"

int main(int argc, char* argv[])
{
    int numEntries, day, month, year, ii;
    int a =0;
    char *journalMessage = NULL;
    Journal *journal;
    FILE* f=NULL;
 
    /*There must only be one command line argument, therefore the number of arguments must not exceed or fall short of two */
    if(argc!=2)
    {
        printf("Invalid number of arguments");
    }
    else
    {
        f=fopen("filename.txt", "r");
        /*If filename.txt doesn't exist then there is nothing to open*/
        if(f==NULL)
        {
            printf("File did not open properly\n");
        }
        else
        {
            fscanf(f, "%d", &numEntries);/*This is to read first line of the file which is the number of entries in the file*/
            journal = (Journal*)malloc(numEntries*sizeof(Journal));
            journalMessage = (char*)malloc(100*sizeof(char));
            for(ii=0; ii<numEntries; ii++) 
            {
                fscanf(f, "%d/%d/%d", &day, &month, &year);/*fscanf to get the date of an entry in it's specified format*/
                fgets(journalMessage, 100, f);/*fgets to get the message below the date which is a string that can be up to 100 characters*/

                (journal[ii].day)=day;/*extracting day from the iith struct */
                (journal[ii].month)=month;/*extracting month from the iith struct*/
                (journal[ii].year)=year;/*extracting year from the iith struct*/
                (journal[ii].message)=journalMessage;/*extracting the journal message from the iith struct*/
          

            a = strtol(argv[1], NULL, 10);/*command line argument is the journal entry index. This converts it from a string to an int*/

            if((a<numEntries)&&(a>0))/*you can't exceed the number of entries in the journal not can you have a negative number of entries*/
            {
                printf("%d-%d-%d: %s", journal[a].year, journal[a].month, journal[a].day, journal[a].message);/*gets year, month, day, message from the ath journal struct in the format year-month-day: message*/
            }
            fclose(f);/*closes the file*/
            free(journal);/*frees allocated memory for journal struct*/
            free(journalMessage);/*frees memory allocated to the char*/
        }
    }
            
    return 0;
}

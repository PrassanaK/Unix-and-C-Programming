/* This code is part of Worksheet 2 (for UCP 120). */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>  /* <-- Actually part of UNIX rather than C; needed for the sleep() function. */

#include "download.h"

#define MIN_DOWNLOAD_SIZE 0
#define MAX_DOWNLOAD_SIZE 1000000
#define MIN_DOWNLOAD_RATE 50000
#define MAX_DOWNLOAD_RATE 100000

int main(void)
{
    int currentTime, startTime, bytes, totalBytes;

    srand(time(NULL));
    startTime = rand();
    totalBytes = MIN_DOWNLOAD_SIZE + rand() % (MAX_DOWNLOAD_SIZE - MIN_DOWNLOAD_SIZE);

    printf("startTime == %d, totalBytes == %d\n(Press Ctrl-C to exit)\n", startTime, totalBytes);

    currentTime = startTime;
    bytes = 0;
    do
    {
        sleep(1);
        bytes += MIN_DOWNLOAD_RATE + rand() % (MAX_DOWNLOAD_RATE - MIN_DOWNLOAD_RATE);
        if(bytes > totalBytes)
        {
            bytes = totalBytes;
        }
        currentTime++;

        printf("\ntime == %d, bytes == %d\n-------------------\n", currentTime, bytes);

        printf("ELAPSED_TIME: %d seconds\n", ELAPSED_TIME(currentTime, startTime));
        printf("PERCENT_COMPLETE: %.2f%%\n", PERCENT_COMPLETE((double)bytes, (double)totalBytes));
        printf("DOWNLOAD_SPEED: %.2f bytes/second\n", DOWNLOAD_SPEED(currentTime, startTime, (double)bytes));
        printf("TOTAL_TIME: %.2f seconds\n", TOTAL_TIME(currentTime, startTime, (double)bytes, (double)totalBytes));
        printf("REMAINING_TIME: %.2f seconds\n", REMAINING_TIME(currentTime, startTime, (double)bytes, (double)totalBytes));
    }
    while(bytes < totalBytes);

    return 0;
}


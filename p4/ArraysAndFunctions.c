#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int sum(int A[], int length);
int max(int A[], int length);
void reverse(int A[], int length);
void convertString(char* charArray[], int intArray[], int length);
void arrayOutput(int intArray[], int length);

int main(void)
{
}

int sum(int A[], int length)
{
    int i, sum;
    sum = 0;
    for(i=0;i<length;i++)
    {
        sum = sum + A[i];
    }
    return sum;
}

int max(int A[], int length)
{
    int i, max;
    max = 0;
    for(i=0;i<length;i++)
    {
        if(A[i] > A[max])
        {
            max = i;
        }
    }
    return max;
}

void reverse(int A[], int length)
{
    while(length >= 0)
    {
        int i;
        for(i=0;i<=length;i++)
        {
            int temp;
            temp = A[i];
            A[i] = A[i+1];
            A[i+1] = temp;
        }
    }
}

void convertString(char* charArray[], int intArray[], int length)
{
    int val;
    char* str[] = {"7","1","14","-5"};

    int ii;
    for(ii=0; ii<length; ii++)
    {
        val = atoi(str[ii]);
        intArray[ii] = val;       
    } 
}

void arrayOutput(int intArray[], int length)
{
    int ii;
    for(ii=0; ii<length; ii++)
    {
        printf("%d", intArray[ii]); 
    }
}

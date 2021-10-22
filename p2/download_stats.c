#include <stdio>

double elapsedTime(double time, double startTime)
{
   double elapTime = (((time) - (startTime))*3600);
   return elapTime;
}

double percentComplete(double bytes, double totalBytes)
{
    return (bytes/(((time)-startTime))/bytes);
}

double downloadSpeed(double time, double startTime, double bytes)
{
    return (bytes/(((time)-(startTime))*3600));
}

double totalTime(double time, double startTime, double bytes, double totalBytes)
{
    ((totalBytes(time-startTime))/bytes);
}

double remainingTime(double time, double startTime, double bytes, double totalBytes)
{
    (((totalBytes(time - startTime))/bytes)-(((time) - (startTime))*3600));
}

#define ELAPSED_TIME(time, starTime) (((time) - (startTime))*3600)
#define PERCENT_COMPLETE(bytes, totalBytes) (((bytes)/totalBytes)*100)
#define DOWNLOAD_SPEED(time, startTime, bytes) (bytes/(((time)-(startTime))*3600))
#define TOTAL_TIME(time, startTime, bytes, totalBytes) ((totalBytes(time - startTime))/bytes) 
#define REMAINING_TIME(time, startTime, bytes, totalBytes) (((totalBytes(time - startTime))/bytes)-(((time) - (startTime))*3600))

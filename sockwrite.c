#include "sockwrite.h"

/*
sockWrite
input:      socket descriptor, byte string, bytes
output:     bytes written
function:   Writes a given number of bytes to a socket and returns how many were succeessfully written
*/
int sockWrite(int socket, char *src, int bytes)
{
    char outBuffer[1024] = {0};
    int bytesWritten;
    int bytesToWrite;
    if(bytes > 1023)
    {
        printf("Output exceeds buffer\n");
        return -1;
    }
    strncpy(outBuffer, src, bytes);
    if(strlen(outBuffer) < bytes)
    {
        bytesToWrite = strlen(outBuffer);
    }
    else
    {
        bytesToWrite = bytes;
    }
    bytesWritten = write(socket, outBuffer, bytesToWrite);

    return bytesWritten;
}

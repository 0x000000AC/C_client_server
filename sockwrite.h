#ifndef SOCKWRITE
#define SOCKWRITE

//stdio.h contains IO functions
#include <stdio.h>

//string.h contains string handlers
#include <string.h>

//Contains data types for system calls
#include <sys/types.h>

//socket.h contains socket structure definitions
#include <sys/socket.h>

//in.h contains address resolution functions
#include <netinet/in.h>

/*
sockWrite
input:      socket descriptor, byte string, bytes
output:     bytes written
function:   Writes a given number of bytes to a socket and returns how many were succeessfully written
*/
int sockWrite(int socket, char *src, int bytes);

#endif

#ifndef CLIENT
#define CLIENT

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

//contains the socket writer
#include "sockwrite.h"

/*
client
input:      ip address, port
output:     none
function:   Connects to a server and exchanges data
*/
void client(char *addrStr, char *portStr);

#endif

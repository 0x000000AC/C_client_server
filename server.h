#ifndef SERVER
#define SERVER

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
server
input:      port
output:     none
function:   Waits for a connection on port and serves a menu system
*/
void server(char *portStr);

#endif

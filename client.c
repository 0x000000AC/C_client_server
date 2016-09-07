#include "client.h"

/*
client
input:      ip address, port
output:     none
function:   Connects to a server and exchanges data
*/
void client(char *addrStr, char *portStr)
{
    int sFD;
    int bytesRead, bytesWritten;
    struct sockaddr_in serv_addr;

    int port;

    char inBuffer[1500] = {0};
    char outBuffer[1500] = {0};

    //make port an integer
    port = atoi(portStr);

    //Attempt to create socket
    if((sFD = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("Could not create socket\n");
        return;
    }
    
    // set servaddr to 0
    memset(&serv_addr, 0, sizeof(serv_addr));

    //set IPv4 and port of servaddr struct
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    
    //Attempt to set IP address from string
    if(inet_pton(AF_INET, addrStr, &serv_addr.sin_addr) <= 0)
    {
        printf("Could not convert input to IP address\n");
        return;
    }


    printf("Attempting Connection to %s:%d...\n", addrStr, port);

    //Attempt to connect to IP address and port
    if(connect(sFD, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("Could not connect to server %s on port %d\n", addrStr, port);
		    return;
    }

    printf("...Connected!\n");

    // Continuously go through the loop flushing the buffer, reading
    // from the socket, and sending
    while(1)
    {
        memset(outBuffer, 0, sizeof(outBuffer));
        memset(inBuffer, 0, sizeof(inBuffer));
        bytesRead = 0;

        //read from the socket
        bytesRead = read(sFD, inBuffer, sizeof(inBuffer)-1);
    

        if(bytesRead < 0)
        {
            printf("Receive error\n");
        }

        printf("\nReceived %d bytes\n", bytesRead);        

        //print what we received
        printf("%s\n", inBuffer);

        //determine if we should quit
        if(strncmp("Goodbye",inBuffer,7) != 0)
        {
            printf("\nResponse?:  ");
            scanf("%32s", outBuffer);
            bytesWritten = sockWrite(sFD, outBuffer, strlen(outBuffer));
            printf("Sent %d bytes\n", bytesWritten);
        }
        else
        {
            //tear down socket
            close(sFD);
            return;
        }
    }
}


int main(int argc, char *argv[])
{

    if(argc == 3)
    {
        printf("Client Mode\n");
        client(argv[1], argv[2]);
    }
    else
    {
        printf("Useage is:\n");
        printf("Client:  'program serveraddress serverport'\n");
        return -1;
    }


    return 0;
}

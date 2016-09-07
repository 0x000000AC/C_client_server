#include "server.h"

/*
server
input:      port
output:     none
function:   Waits for a connection on port and serves a menu system
*/
void server(char *portStr)
{
    int lFD, cFD, port;
    int bytesRead, bytesWritten;
    struct sockaddr_in serv_addr;

    char inBuffer[32] = {0};

    //convert port to integer
    port = atoi(portStr);

    //Start a listening socket
    lFD = socket(AF_INET, SOCK_STREAM, 0);
    memset(&serv_addr, 0, sizeof(serv_addr));

    //set IPv4 and port
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(port);

    //bind the socket so it can accept connections
    bind(lFD, (struct sockaddr*) &serv_addr, sizeof(serv_addr));

    printf("Listening on port %d\n", port);

    //wait for an incoming connection, allow only 1 connection in queue
    listen(lFD, 1);

    cFD = accept(lFD, (struct sockaddr*)NULL, NULL);

    printf("Connection Accepted\n");

    while(1)
    {
        memset(inBuffer, 0, sizeof(inBuffer));
        //send the output
        bytesWritten = sockWrite(cFD, "1: Do Nothing\n0: Quit", strlen("1: Do Nothing\n0: Quit"));
        printf("Sent %d bytes\n", bytesWritten);

        bytesRead = 0;

        //receive response
        bytesRead = read(cFD, inBuffer, sizeof(inBuffer)-1);

        if(bytesRead < 0)
        {
            printf("Receive error\n");
        }
        printf("Received %d bytes\n", bytesRead);
        printf("Response is: %s\n", inBuffer);

        //act on the response
        switch(atoi(inBuffer))
        {
            case 0:
                //send goodbye and tear down socket
                bytesWritten = write(cFD, "Goodbye", strlen("Goodbye"));
                printf("Ending Session\n");
                close(cFD);
                close(lFD);
                return;
            break;
            case 1:
                printf("Doing nothing\n");
            break;
            default:
                printf("I did not understand that\n");
            break;
        }
    }
}

int main(int argc, char *argv[])
{

    if(argc == 2)
    {
        printf("Starting Server\n");
        server(argv[1]);
    }
    else
    {
        printf("Useage is:\n");
        printf("Server:  'program portname'\n");
        return -1;
    }

    return 0;
}

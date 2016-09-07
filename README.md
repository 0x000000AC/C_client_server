# C_client_server
(personal exploration in tcp/ip in C)

This is a simple client/server program.  The client, server, and socket writing have been broken up into 3 separate files named respectivly with accompanying header files which include the necessary imports.   When the server is run, it waits for incoming connections, one at a time, in it's queue.  Once a connection is established, it sends the option to do nothing or exit the connection.  Simply download all of the files into the same directory, make, and run.

### Example Usage:
In this case, both are talking over localhost

``` sh
#make all
#./server 4444
```
In another bash terminal/tab:
``` sh
#./client 127.0.0.1 4444
```

-------------------------------------------------

### Example Output:
[On server]
``` sh
#./server 4444
Starting Server
Listening on port 4444
Connection Accepted
Sent 21 bytes
Received 1 bytes
Response is: 1
Doing nothing
Sent 21 bytes
Received 1 bytes
Response is: 0
Ending Session
```


[On client]
``` sh
#./client 127.0.0.1 4444
Client Mode
Attempting Connection to 127.0.0.1:4444...
...Connected!

Received 21 bytes
1: Do Nothing
0: Quit

Response?:  1
Sent 1 bytes

Received 21 bytes
1: Do Nothing
0: Quit

Response?:  0
Sent 1 bytes

Received 7 bytes
Goodbye
```




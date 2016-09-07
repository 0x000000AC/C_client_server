CC = gcc

all: server client

server: server.o sockwrite.o
	$(CC) -o server server.o sockwrite.o

client: client.o sockwrite.o
	$(CC) -o client client.o sockwrite.o

clean:
	rm server client *.o

CC = gcc
CFLAGS = -Iinclude -Wall

all: bin/client

bin/client: src/main.c src/mystrfunctions.c src/myfilefunctions.c
	$(CC) $(CFLAGS) src/main.c src/mystrfunctions.c src/myfilefunctions.c -o bin/client

clean:
	rm -f bin/client
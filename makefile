CC = gcc
CFLAGS = -Iinclude -Wall

all: lib/libmyutils.a bin/client_static

obj/mystrfunctions.o: src/mystrfunctions.c include/mystrfunctions.h
	$(CC) $(CFLAGS) -c src/mystrfunctions.c -o obj/mystrfunctions.o

obj/myfilefunctions.o: src/myfilefunctions.c include/myfilefunctions.h
	$(CC) $(CFLAGS) -c src/myfilefunctions.c -o obj/myfilefunctions.o

lib/libmyutils.a: obj/mystrfunctions.o obj/myfilefunctions.o
	ar rcs lib/libmyutils.a obj/mystrfunctions.o obj/myfilefunctions.o

bin/client_static: src/main.c lib/libmyutils.a
	$(CC) $(CFLAGS) src/main.c -Llib -lmyutils -o bin/client_static

clean:
	rm -f obj/*.o lib/*.a bin/client_static
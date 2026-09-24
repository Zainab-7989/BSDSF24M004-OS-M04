CC = gcc
CFLAGS = -Iinclude -Wall

PREFIX = /usr/local
BINDIR = $(PREFIX)/bin
MANDIR = $(PREFIX)/share/man/man3

all: lib/libmyutils.so bin/client_dynamic

obj/mystrfunctions_pic.o: src/mystrfunctions.c include/mystrfunctions.h
	$(CC) $(CFLAGS) -fPIC -c src/mystrfunctions.c -o obj/mystrfunctions_pic.o

obj/myfilefunctions_pic.o: src/myfilefunctions.c include/myfilefunctions.h
	$(CC) $(CFLAGS) -fPIC -c src/myfilefunctions.c -o obj/myfilefunctions_pic.o

lib/libmyutils.so: obj/mystrfunctions_pic.o obj/myfilefunctions_pic.o
	$(CC) -shared obj/mystrfunctions_pic.o obj/myfilefunctions_pic.o -o lib/libmyutils.so

bin/client_dynamic: src/main.c lib/libmyutils.so
	$(CC) $(CFLAGS) src/main.c -Llib -lmyutils -o bin/client_dynamic

install:
	mkdir -p $(BINDIR)
	mkdir -p $(MANDIR)
	cp bin/client_dynamic $(BINDIR)/client
	cp man/man3/mycat.1 $(MANDIR)/mycat.3

clean:
	rm -f obj/*.o lib/*.so lib/*.a bin/client*
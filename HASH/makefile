CFLAGS = -Wall -Wextra -g -std=c99
CC = gcc

all: myht

# gera o executável
myht: main.o hashtable.o
	$(CC) -o myht main.o hashtable.o

# compila hashtable.c
hashtable.o: hashtable.c hashtable.h
	$(CC) -c $(CFLAGS) hashtable.c

# compila a main
main.o: main.c hashtable.h
	$(CC) -c $(CFLAGS) main.c

clean:
	rm -f *.o *~ myht


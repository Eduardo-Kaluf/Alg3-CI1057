CFLAGS = -Wall -Wextra -g -std=c99
CC = gcc

# gera o executável
myrb: main.o bst.o
	$(CC) -o myrb main.o bst.o

# compila bst.c
bst.o: bst.c bst.h
	$(CC) -c $(CFLAGS) bst.c

# compila tp1.c
main.o: main.c bst.h
	$(CC) -c $(CFLAGS) main.c

clean:
	rm -f *.o *~ main
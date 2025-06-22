CFLAGS = -Wall -Wextra -g -std=c99
CC = gcc

# gera o executável
myrb: main.o bst.o
	$(CC) -o bst main.o bst.o

# compila bst.c
bst.o: bst.c bst.h
	$(CC) -c $(CFLAGS) bst.c

main.o: main.c bst.h
	$(CC) -c $(CFLAGS) main.c

clean:
	rm -f *.o *~ main

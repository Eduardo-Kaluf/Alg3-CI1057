CFLAGS = -Wall -Wextra -g -std=c99
CC = gcc

# gera o executável
myrb: main.o rb.o
	$(CC) -o myrb main.o rb.o

# compila rb.c
rb.o: rb.c rb.h
	$(CC) -c $(CFLAGS) rb.c

# compila tp1.c
main.o: main.c rb.h
	$(CC) -c $(CFLAGS) main.c

clean:
	rm -f *.o *~ main
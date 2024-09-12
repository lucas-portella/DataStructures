CC = gcc
FLAGS = -Wall -Wextra

all: testa_lista

testa_lista: list.o testa_lista.c
	$(CC) $(FLAGS) testa_lista.c list.o -o testa_lista

list.o: list.h list.c
	$(CC) $(FLAGS) -c list.c

clean:
	rm -f *.o

purge: clean
	rm -f testa_lista

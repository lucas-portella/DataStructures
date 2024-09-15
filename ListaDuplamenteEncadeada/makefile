CC = gcc
CFLAGS = -Wall -Wextra

all: dlist.o testa_dlist
	./testa_dlist
	
dlist.o: dlist.c dlist.h
	$(CC) $(CFLAGS) -c dlist.c

testa_dlist: dlist.o testa_dlist.c
	$(CC) $(CFLAGS) dlist.o testa_dlist.c -o testa_dlist

clean:
	rm -f *.o

purge: clean
	rm -f testa_dlist

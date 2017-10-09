## Daniel Hayden
## Date: 4/10/17
## Makefile g++

CC=g++
CFLAGS=-I.

DEPS = Semaphore.h
OBJ = Semaphore.o rendezvous.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

Semaphore: $(OBJ)
	g++ -o $@ $^ $(CFLAGS)


CLEAN:
	rm *.o

## Daniel Hayden
## Date: 4/10/17
## Makefile g++
## Note this makefile was tested and working on mac

CC=g++
CFLAGS=-I.
LDFLAGS=-pthread 
DEPS = Semaphore.h
OBJ = Semaphore.o rendezvous.o
CXXFLAGS	= -std=c++11 -ggdb -Wall
DOXYGEN = doxygen

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

Semaphore: $(OBJ)
	g++ -o $@ $^ $(CFLAGS)

clean:
	rm *.o Semaphore

docs: 
	$(DOXYGEN) doxConfig
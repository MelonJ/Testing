CC = clang

.PHONY: clean all

all: main

main: main.o encryption.o
	$(CC) -o main main.o encryption.o

main.o: main.c encryption.h
	$(CC) -c main.c encryption.h

encryption.o: encryption.c encryption.h
	$(CC) -c encryption.c encryption.h


clean:
	rm *.o main encryption.h.gch


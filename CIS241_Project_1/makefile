CC = clang
CFLAGS = -02

.PHONY: clean all

all: main

main: main.o encryption.o
	$(CC) $(CFLAGS) -o main main.o encryption.o

main.o: main.c encryption.h
	$(CC) $(CLFAGS) -c main.c encryption.h

encryption.o: encryption.c encryption.h
	$(CC) $(CFLAGS) -c encryption.c encryption.h


clean:
	rm *.o main


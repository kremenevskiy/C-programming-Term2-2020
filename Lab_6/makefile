all: build run clean

build: main.o TripleTree.o
	gcc main.o TripleTree.o -o program

run:
	./program

main.o: main.c
	gcc -c main.c

TripleTree.o: TripleTree.h
	gcc -c TripleTree.h -o TripleTree.o

clean:
	rm -f *.o *.gch program
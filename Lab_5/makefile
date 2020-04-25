
all: build run clean

build: main.o stack.o
	gcc main.o stack.o -o program

main.o: main.c
	gcc -c main.c

stack.o: Stack.h
	gcc -c Stack.h -o stack.o

run: program
	./program

clean:
	rm -f *.o *.gch program
	



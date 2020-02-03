#Makefile
#target: dependencies
#	action

all: main

main: arvore-binaria.o independent.o
	gcc main.c -o main arvore-binaria.o independent.o

arvore-binaria.o: arvore-binaria.c
	gcc -c arvore-binaria.c

independent.o: independent.c
	gcc -c independent.c

clean:
	rm *o
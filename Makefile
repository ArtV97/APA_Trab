#Makefile
#target: dependencies
#	action

all: main

main: lista-encadeada.o arvore-binaria.o independent.o
	gcc main.c -o main lista-encadeada.o arvore-binaria.o independent.o

lista-encadeada.o: lista-encadeada.c
	gcc -c lista-encadeada.c

arvore-binaria.o: arvore-binaria.c
	gcc -c arvore-binaria.c

independent.o: independent.c
	gcc -c independent.c

clean:
	rm *o

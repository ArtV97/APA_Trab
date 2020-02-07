#include<stdio.h>
#include<stdlib.h>


typedef struct noLista {
	int info;
	struct noLista *prox;
} no;

typedef struct lista_encadeada{
	int qtdElem;
	no *prim;
} listaEnc;

listaEnc *criaLista();
int removePos(listaEnc *l, int pos);
void insereIni(listaEnc *l, int a);
void imprimeLista(listaEnc *l);
int buscaLista(listaEnc *l, int a);
void freeList(listaEnc *l);
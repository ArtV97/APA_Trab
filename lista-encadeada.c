#include "lista-encadeada.h"

listaEnc *criaLista(){
	listaEnc * l = (listaEnc*)malloc(sizeof(listaEnc));
    l->prim = NULL;
	l->qtdElem = 0;
    return l;
}

int removePos(listaEnc *l, int pos){
	int value;
	no *noAux = l->prim;
	if(pos != 0){
		no *noAnt;
		for(int i = 0; i < pos; i++){
			noAnt = noAux;
			noAux = noAux->prox;
		}
		noAnt->prox = noAux->prox;
		value = noAux->info;
	}
	else{
		value = noAux->info;
		l->prim = l->prim->prox;
	}
	free(noAux);
	l->qtdElem -= 1;
	return value;
}

void insereIni(listaEnc *l, int a){
	no *novo = (no*)malloc(sizeof(no));
    novo->info = a;
    novo->prox = l->prim;
    l->prim = novo;
	l->qtdElem += 1;
}

void imprimeLista(listaEnc *l){
	no *noAux = l->prim;
	while(noAux != NULL){
		printf("%d ", noAux->info);
		noAux = noAux->prox;
	}
	printf("\n");
}

int buscaLista(listaEnc *l, int a){
	no *noAux = l->prim;
	int i = -1;
	while(noAux != NULL){
		i++;
		if(noAux->info == a){
			return i;
		}
		noAux = noAux->prox;
	}
	return -1;
}


void freeList(listaEnc *l){
	no *noAux = l->prim;
	while(noAux != NULL){
		no *prox = noAux->prox;
		free(noAux);
		noAux = prox;
	}
	free(l);
}

#include "arvore-binaria.h"
#include<time.h>


TNoA *inicializa_A(void) {
    return NULL;
}


void imprime_A(TNoA *nodo, int tab) {
    for (int i = 0; i < tab; i++) {
        printf("-");
    }
    if (nodo != NULL) {
        printf("%d\n", nodo->info);
        imprime_A(nodo->esq, tab + 2);
        printf("\n");
        imprime_A(nodo->dir, tab + 2);
    } else printf("vazio");
}


void posOrdem(TNoA* a){
	if (a!= NULL){
		posOrdem(a->esq);
		posOrdem(a->dir);
		printf("%d", a->info);
	}
}


TNoA *criaNo(int a) {
    TNoA *novo;
    novo = (TNoA *) malloc(sizeof(TNoA));
    novo->info = a;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}


TNoA *insere(TNoA *r, int a){
	if(r != NULL){
		if(a > r->info)
			r->dir = insere(r->dir, a);
		else
			r->esq = insere(r->esq, a);
	}
	else{
		r = criaNo(a);
	}
	return r;
}


TNoA *criaArvoreAleatoria(TNoA *r, int n){
	srand(time(NULL));
	listaEnc *lista = criaLista();
	for(int i = 1; i < n+1; i++){
		insereIni(lista, i);
	}
	while(lista->qtdElem > 0){ //enquanto houver elementos na lista
		int pos = rand() % lista->qtdElem; //sorteia uma posicao da lista
		int value = removePos(lista, pos);
		r = insere(r, value); //insere o elemento removido na arvore
	}
	freeList(lista);
	return r;
}


void freeArvore(TNoA *r){
	if(r != NULL){
		freeArvore(r->esq);
		freeArvore(r->dir);
		free(r);
	}
}
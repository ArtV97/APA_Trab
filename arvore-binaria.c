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
        printf("%c\n", nodo->info);
        imprime_A(nodo->esq, tab + 2);
        printf("\n");
        imprime_A(nodo->dir, tab + 2);
    } else printf("vazio");
}


void posOrdem(TNoA* a){
	if (a!= NULL){
		posOrdem(a->esq);
		posOrdem(a->dir);
		printf("%c", a->info);
	}
}


TNoA *criaNo(char ch) {
    TNoA *novo;
    novo = (TNoA *) malloc(sizeof(TNoA));
    novo->info = ch;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}


TNoA *criaArvoreAleatoria(TNoA *r, int *count, int n){
	//TODO
}

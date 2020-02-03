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
	if(*count < n){
		if(r != NULL){
			r->esq = criaArvoreAleatoria(r->esq, count, n);
			r->dir = criaArvoreAleatoria(r->dir, count, n);
		}
		if(*count == 0){
			r = criaNo('R');
			*count += 1;
			while(*count < n){
				r->esq = criaArvoreAleatoria(r->esq, count, n);
				r->dir = criaArvoreAleatoria(r->dir, count, n);
			}
		}
		else{
			srand(time(NULL)); //passa uma seed baseada no tempo, ou seja, uma seed "dinâmica"
			int p = rand() % 10; //sorteia um numero de 0 até 9
			if(p > 4){
				r = criaNo('D');
				*count += 1;
				r->esq = criaArvoreAleatoria(r->esq, count, n);
				r->dir = criaArvoreAleatoria(r->dir, count, n);
			}
		}

	}
	return r;
	
}

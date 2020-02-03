#include "independent.h"


int main(){
	printf("Digite o numero de nos da arvore: ");
	int n;
	scanf("%d", &n);
	TNoA *raiz = NULL;
	int count = 0;
	raiz = criaArvoreAleatoria(raiz, &count, n);
    imprime_A(raiz, 0);
    printf("\n");
    printf("Tamanho do maior conjunto independente: %d\n", conjInMaxPD(raiz, n));
	return 0;
}
/*raiz = criaNo('A');
    raiz->esq = criaNo('R');
    raiz->esq->esq = criaNo('T');
    raiz->esq->dir = criaNo('H');
    raiz->dir = criaNo('U');
    raiz->dir->esq = criaNo('R');
    raiz->dir->dir = criaNo('!');*/

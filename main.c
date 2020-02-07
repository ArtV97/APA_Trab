#include "independent.h"


int main(){
	printf("Digite o numero de nos da arvore: ");
	int n;
	scanf("%d", &n);
	TNoA *raiz = NULL;
	raiz = criaArvoreAleatoria(raiz, n);
    imprime_A(raiz, 0);
    printf("\n");
	listaEnc *results = criaLista();
	results = conjInMaxPD(raiz,n);
    printf("Tamanho do maior conjunto independente: %d\n", results->qtdElem);
	printf("Conjunto: ");
	imprimeLista(results);
	
	freeList(results);
	getchar();
	return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct noA {
    char info;
    struct noA *esq;
    struct noA *dir;
} TNoA;

TNoA *inicializa_A(void);
void imprime_A(TNoA *nodo, int tab);
void posOrdem(TNoA* a);
TNoA *criaNo(char ch);
TNoA *criaArvoreAleatoria(TNoA *r, int *count, int n);

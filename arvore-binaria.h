#include "lista-encadeada.h"

typedef struct noA {
    int info;
    struct noA *esq;
    struct noA *dir;
} TNoA;

TNoA *inicializa_A(void);
void imprime_A(TNoA *nodo, int tab);
void posOrdem(TNoA* a);
TNoA *criaNo(int a);
TNoA *insere(TNoA *r, int a);
TNoA *criaArvoreAleatoria(TNoA *r, int n);

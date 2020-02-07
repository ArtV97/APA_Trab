#include "arvore-binaria.h"


typedef struct independent{
	int value; //tamanho do conj independente dessa subárvore
	int elem; //o valor do elemento
	int fEsq; //posicao do filho da esquerda na estrutura
	int fDir; //posicao do filho da direita na estrutura
} Ind;


Ind *inicializaInd(int value, int elem, int fEsq, int fDir);
int conjInMaxRecur(TNoA* r);
int preenchePosOrdem(Ind **v, TNoA *r, int *pos);
void encontraConj(Ind **v, listaEnc *conjI, int n);
listaEnc *conjInMaxPD(TNoA* r, int n);
//int *conjInMaxPD(TNoA* r, int n);

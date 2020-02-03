#include "arvore-binaria.h"


typedef struct independent{
	int value;
	int fEsq; //posicao do filho da esquerda na estrutura
	int fDir; //posicao do filho da direita na estrutura
} Ind;


Ind *inicializaInd(int value, int fEsq, int fDir);
int conjInMaxRecur(TNoA* r);
int preenchePosOrdem(Ind **v, TNoA *r, int *pos);
int conjInMaxPD(TNoA* r, int n);

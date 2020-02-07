#include "independent.h"


Ind *inicializaInd(int value, int elem, int fEsq, int fDir){
	Ind *novo = (Ind*)malloc(sizeof(Ind));
	novo->value = value;
	novo->elem = elem;
	novo->fEsq = fEsq;
	novo->fDir = fDir;
	return novo;
}


int conjInMaxRecur(TNoA* r){
	if (r == NULL){
		return 0;
	}
	else if(r->dir == NULL && r->esq == NULL){
		return 1;
	}
	int netos = 1;
	netos += conjInMaxRecur(r->esq->esq);
	netos += conjInMaxRecur(r->esq->dir);
	netos += conjInMaxRecur(r->dir->esq);
	netos += conjInMaxRecur(r->dir->dir);

	int filhos = conjInMaxRecur(r->esq) + conjInMaxRecur(r->dir);

	if (netos > filhos){
		return netos;
	}
	else{
		return filhos;
	}
}

int preenchePosOrdem(Ind **v, TNoA *r, int *pos){
	if (r != NULL){
		int f_esq = preenchePosOrdem(v, r->esq, pos); //posicao do filho da esq no vetor
		int f_dir = preenchePosOrdem(v, r->dir, pos); //posicao do filho da dir no vetor
		*pos += 1; //posicao do no em v
		v[*pos] = inicializaInd(0, r->info, f_esq, f_dir);

		int netos = 1;
		netos += v[v[v[*pos]->fEsq]->fEsq]->value;
		netos += v[v[v[*pos]->fEsq]->fDir]->value;
		netos += v[v[v[*pos]->fDir]->fEsq]->value;
		netos += v[v[v[*pos]->fDir]->fDir]->value;
		
		int filhos = 0;
		filhos += v[v[*pos]->fEsq]->value;
		filhos += v[v[*pos]->fDir]->value;
		
		if (netos > filhos){
			v[*pos]->value = netos;
		}
		else{
			v[*pos]->value = filhos;
		}
		return *pos;
	}
	return 0;
}


void encontraConj(Ind **v, listaEnc *conjI, int n){ //encontrando o conj independente
	if(n != 0){
		if(v[n]->value == v[v[n]->fEsq]->value + v[v[n]->fDir]->value){
			//adicionar filhos
			encontraConj(v, conjI, v[n]->fEsq);
			encontraConj(v, conjI, v[n]->fDir);
		}
		else{
			//adiciona netos
			insereIni(conjI, v[n]->elem);
			encontraConj(v, conjI, v[v[n]->fEsq]->fEsq);
			encontraConj(v, conjI, v[v[n]->fEsq]->fDir);
			encontraConj(v, conjI, v[v[n]->fDir]->fEsq);
			encontraConj(v, conjI, v[v[n]->fDir]->fDir);
		}
	}
}


listaEnc *conjInMaxPD(TNoA* r, int n){
	if (r != NULL){
		Ind **v = (Ind**)malloc((n+1) * sizeof(Ind));
		v[0] = inicializaInd(0, 0, 0, 0); //A primeira posicao representa NULL
		int position = 0;
		preenchePosOrdem(v, r, &position); //preenche a estrutura
		listaEnc *conjI = criaLista();
		encontraConj(v, conjI, n); //a partir da estrutura encontra o conj
		printf("Recorrencia: ");
		for(int i =0; i < n+1; i++){
			printf("%d ", v[i]->value);
		}
		printf("\n");
		for(int i = 0; i < n+1; i++)
			free(v[i]);
		return conjI;
	}
	return 0;
}


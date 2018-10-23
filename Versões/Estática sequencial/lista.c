#include "lista.h"

void cria_lista(Lista *L) {
	L->ini = 0;
	L->fim = 0;
	L->qtd = 0;
}

void insere_na_lista(Lista *L, obj_b x) {

	L->elem[L->fim++] = x;	
	L->qtd++;

	if(L->fim == TamLista)
		L->fim = 0;
}
//Nao testei acho q ta certo.
obj_b remove_da_lista(Lista *L, int i) {	
	int j = L->fim - 1;
	obj_b aux = L->elem[i];
	int M = L->qtd;

	if(i == L->ini && L->qtd > 1)
		L->ini++;
	else if(i == L->fim)
		L->fim--;

	while(i < j) {		
		L->elem[i] = L->elem[i + 1];
		i++;
	}

	L->qtd--;
	
	return aux;
}
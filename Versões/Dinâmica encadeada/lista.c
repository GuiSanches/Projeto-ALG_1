#include "lista.h"

int CriaLista(Lista *L) {
	L->inic = NULL;
	L->fim = NULL;
}

int insere(Lista *L, elem x) {
	No *aux = (No*)malloc(sizeof(No));
	if(aux == NULL)
		return 0;

	aux->info = x;
	//Lista vazia
	if(L->inic == NULL) {
		aux->ant = NULL;
		aux->prox = NULL;
		L->inic = aux;
		L->fim = aux;
	}else {//Insere no fim
		aux->ant = L->fim;
		aux->prox = NULL;
		L->fim->prox = aux;		
		L->fim = aux;
	}

}

int remover(Lista *L, int intervalo, Fila *C) {
	No *atual = L->inic;
	No *aux;
	int i, j = 0;
	//Lista circular, ultimo aponta para o primeiro
	L->fim->prox = L->inic
	//Remove todos os nos da lista
	do{	
		//Remove K nos
		Remover:
			i = 1;
			while(i < intervalo) {			
				 atual = atual->prox;
				 i++;
			}
			j += i;
			//se nao percorreu a lista toda, falta brinquedos a remover
			if(j < L->tam) {		
				//Inicio Remocao do no					
				atual->prox->ant = atual->ant;
				atual->ant->prox = atual->prox;			
				aux = atual->prox;
				//Se caixa estiver cheia insere na fila e esvazia a caixa.
				if(!push(&caixa,atual->info)) {
					insere_Fila(&caixa, C);
					esvazia_pilha(&caixa);
				}
				//remove No e atualiza ponteiro atual para o proximo
				free(atual);		
				atual = aux;
				L->tam--;
				//Fim remocao do no
				goto Remover;
			}
		intervalo--;
		j = 0;			
		}while(!vazia_lista(L));//Se nao removeu todos os brinquedos ainda, continue removendo
	//Atualiza inicio e fim da lista
	L->inic = NULL;
	L->Fim = NULL;	
	return 0;
}

int imprimeLista(Lista *L) {
	No *i = L->inic;

	while(i != NULL) {
		printf("%d ", i->info);
		i = i->prox;
	}
	return 1;
}

void ApagaLista(Lista *L) {
	free(L);	
}

int vazia_lista(Lista *L) {
	return L->inic == NULL ? 1:0;
}






int remover(Lista *L, int intervalo) {
	L->fim->prox = L->inic

	No *atual = L->inic;
	No *aux;
	int i;

	while(L->inic != L->fim) {
		//Procura pato
		i = 1;
		while(i < intervalo) {			
			 atual = atual->prox;
			 i++;
		}		
		//Inicio remocao do no					
		atual->prox->ant = atual->ant;
		atual->ant->prox = atual->prox;			
		aux = atual->prox;
		if(L->fim == atual)
			L->fim = L->fim->ant;
		else if(L->inic == atual)
			L->inic = L->inic->prox;			
		free(atual);		
		atual = aux;
		L->tam--;
		//Fim remocao do no
	}
	atual->ant = NULL;
	atual->prox = NULL;
	return 0;
}

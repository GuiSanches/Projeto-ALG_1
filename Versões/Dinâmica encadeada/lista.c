#include "lista.h"

void cria_lista(Lista *L) {
	L->inic = NULL;
	L->fim = NULL;
}

int insere_na_lista(Lista *L, obj_b x) {
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
		L->tam = 1;
	}else {//Insere no fim
		aux->ant = L->fim;
		aux->prox = L->inic;
		L->fim->prox = aux;		
		L->fim = aux;
		L->tam++;
		L->inic->ant = L->fim;
	}

	return 1;
}
//Como os brinquedos sao transportados de uma esteira para uma caixa faria mais sentido criar 
int remover(Lista *L, int k, Fila *C, int p) {
	No *atual = L->inic;
	No *aux;//No auxiliar para remocao
	No *aux_novo_inic;//Marca novo inicio da lista para cada ciclo de remocao
	int i, flag = 0, j = 0;
	Pilha Caixa;
	Pilha *ptrCaixa;

	cria_pilha(&Caixa, p);

	//Sub-rotina para remocao de um no. Poderia ser substituido por recursividade.
	Remover:
	//Inicio Remocao do no					
		atual->prox->ant = atual->ant;
		atual->ant->prox = atual->prox;			
		aux = atual->prox;
		//Insere brinquedo na Caixa(PILHA) e encaminha a Caixa cheia para a fila de caixas.
																								printf("Teste 1 %d: \n%s %s\n\n", j, atual->info.nSerie, atual->info.modelo);
		brinquedo_caixa(&Caixa, atual, C, p);
		//Apaga o no, decrementa numero de elementos da lista e atualiza o ponteiro atual para proxima posicao valida
		free(atual);				
		atual = aux;					
	//Fim remocao do no
	i = 1;	
	//Procura k-esimo brinquedo a ser removido. Note que quando k for 1 nao havera a busca.
	while(i < k) {						
		atual = atual->prox;		
		i++;
		//armazena inicio da proxima sequencia de remocoes, quando o intervalo(int k) sera decrescido.
		if(!flag) {
			aux_novo_inic = atual->ant;
																								//printf("Teste 2: \n%s %s\n\n",aux_novo_inic->info.nSerie, aux_novo_inic->info.modelo);
			flag = 1;
		}
	}
	j+=i;	
	
	//Se tiver pelo menos 2 elementos na esteira ainda falta remover brinquedos
	if(L->tam > 1) {
		//Se verdadeiro, todos os brinquedos ja foram removidos em um ciclo, decremente o K e INICIE UM NOVO CICLO DE REMOCAO.
		if(j > L->tam) {
			atual = aux_novo_inic;
			L->tam -= j/i + 1;																										
			flag = 0;
			j = 0;			
		}		
		goto Remover;
	}//Remova o ultimo brinquedo da lista
	else {  
		ptrCaixa = &Caixa;
		if(cheia_pilha(ptrCaixa)) {
																										printf("Cheia 4: \n%s %s\n\n",atual->info.nSerie, atual->info.modelo);		
			insere_Fila(C, ptrCaixa);
			free(ptrCaixa);
			cria_pilha(ptrCaixa, p);			
		}else {
																										printf("!cheia 5: \n%s %s\n\n",atual->info.nSerie, atual->info.modelo);			
		}
		push(ptrCaixa, &atual->info);
		insere_Fila(C, ptrCaixa);
		free(ptrCaixa);
	}

	free(atual);

	return 0;
}	

int brinquedo_caixa(Pilha *caixa, No *brinquedo, Fila *Caixas, int p) {
	int cont = 0;

	if(cheia_pilha(caixa)) {
		insere_Fila(Caixas, caixa);
		free(caixa);
		cria_pilha(caixa, p);//cria nova caixa de brinquedos
		push(caixa, &brinquedo->info);
		return 1;	
	}else	
		push(caixa, &brinquedo->info);		
		//Se o brinquedo nao tiver enchido a caixa retorna 0			
	return 0;
}

int vazia_lista(Lista *L) {
	return L->inic == NULL ? 1:0;
}

//TAD PILHA

void cria_pilha(Pilha *P, int p) {
	P->topo = NULL;
	P->tam = 0;
	P->max = p;
}

int push(Pilha *P, obj_b *x) {
	No *aux = (No*)malloc(sizeof(No));
	if(aux == NULL)
		return 0;
	else {
		//Armazena dados do brinquedo		
		aux->info = *x;		
		//Se pilha estiver vazia insira o primeiro no, se nao ensira os nos seguintes.
		if(P->topo == NULL) {
			P->topo = aux;
			aux->prox = NULL;			
			P->tam = 1;
		}else {
			aux->prox = P->topo;
			P->topo = aux;
			P->tam++;
		}
	}

	return 1;
}

int tam(Pilha *P) {
	return P->tam;
}

obj_b top(Pilha *P) {
	return P->topo->info;
}

int cheia_pilha(Pilha *P) {
	return P->tam == P->max ? 1:0;
}

//TAD FILA

void cria_fila(Fila *F) {
	F->inic = NULL;
	F->fim = NULL;
}

int insere_Fila(Fila *F, Pilha *X) {
	//Cria um no do tipo pilha
	No_Pilha *aux = (No_Pilha*) malloc(sizeof(No_Pilha));
	if(aux == NULL)
		return 0;
	else {
		//copia a pilha x como informacao do no aux, em seguida o no apontara para vazio(Insercao no fim)
		aux->info = *X;
		aux->prox = NULL;
		if(F->inic == NULL) {
			//Fila vazia, primeiro e ultimo no sao iguais.
			F->inic = aux;
			F->fim = aux;
		}else {
			//Atualiza o novo fim da fila
			F->fim->prox = aux;
			F->fim = aux;
		}
	}	
	
	return 1;
}

int vazia_fila(Fila *F) {
	return F->inic == NULL ? 1:0;
}

int remove_fila(Fila *F, Pilha *dest) {
	//Se houver pilhas a serem removidas passe para pilha destino os dados da primeira pilha da fila
	if(!vazia_fila(F)) {
		dest->tam = F->inic->info.tam;
		dest->topo = F->inic->info.topo;
		dest->max = F->inic->info.max;
		F->inic = F->inic->prox;
		return 1;					
	}

	return 0;
}

void imprime_fila(Fila *F) {
	Fila aux;
	Pilha caixa;
	obj_b brinquedo;
	int i = 0;
	int tamanho;

	cria_fila(&aux);
	cria_pilha(&caixa, 100000);	

	while(remove_fila(F, &caixa)) {		
		brinquedo = top(&caixa);	
		tamanho = tam(&caixa);	
		printf("%s %d %s %s %s %s %s %d \n",
				"Caixa", i+1, ": brinquedo", brinquedo.nSerie, " ", brinquedo.modelo, "- quantidade ", tamanho);
		i++;				
	}
}



















































/*
int remover(Lista *L, int intervalo) {
	No *atual = L->inic;
	No *aux;
	int i, j = 0;	
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
}*/

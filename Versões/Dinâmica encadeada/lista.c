#include "lista.h"

void cria_lista(Lista *L) {
	L->inic = NULL;
	L->fim = NULL;
}
//Lista circular
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
	int i, flag = 1;
	Pilha Caixa; //Caixa de brinquedo
	Pilha *ptrCaixa;

	//Cria caixa de brinquedo
	cria_pilha(&Caixa, p);
	//Sub-rotina para remocao de um no. Poderia ser substituido por recursividade ou um do-while.
	Remover:
	//Inicio Remocao do no					
		atual->prox->ant = atual->ant;
		atual->ant->prox = atual->prox;			
		aux = atual->prox;			
		//Insere brinquedo na Caixa(PILHA) e encaminha a Caixa para a fila de caixas quando necessario.																								
		brinquedo_caixa(&Caixa, atual, C, p, L->tam);			
		//printf("Removido: %s %s %d. Flag:%d\n", atual->info.modelo, atual->info.nSerie, k, flag);	PARA VER A REMOCAO ACONTECENDO DESCOMENTE ESTA LINHA
		//Apaga o no, decrementa numero de elementos da lista e atualiza o ponteiro atual para proxima posicao valida
		free(atual);	
		L->tam--;				
		atual = aux;						
	//Fim remocao do no
	i = 1;	
	//Procura k-esimo brinquedo a ser removido. Note que quando k for 1 nao havera a busca.
	while(i < k) {	
		//armazena inicio da proxima sequencia de remocoes, quando o intervalo(int k) sera decrescido.
		if(flag) {
			aux_novo_inic = atual;																								
			flag = 0;			
		}/*Verifica se terminou um ciclo de remocao para isso a flag precisa sinalizar(flag == 0) que ha um ponteiro para o inicio de um novo ciclo.
		   Se encerrou um ciclo o intervalo sera decrementado e o ponteiro atual inicializara a partir do inicio do novo ciclo */
		else {
			if(atual->prox == aux_novo_inic || atual == aux_novo_inic) {
				flag = 1;
				k--;
				i = k + 1;
			}
			if(atual == aux_novo_inic)//nao deve atualizar ponteiro atual			
				break;			
		}		
		atual = atual->prox;				
		i++;		
	}//Remova enquanto houver brinquedos na esteira
	if(L->tam > 0)			
		goto Remover;

	return 0;	
}	

int brinquedo_caixa(Pilha *caixa, No *brinquedo, Fila *Caixas, int p, int tam) {
	int cont = 0;

	if(cheia_pilha(caixa)) {
		insere_Fila(Caixas, caixa);
		free(caixa);
		cria_pilha(caixa, p);		
	}
	push(caixa, &brinquedo->info);
	if(tam == 1) {
		insere_Fila(Caixas, caixa);		
	}		
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
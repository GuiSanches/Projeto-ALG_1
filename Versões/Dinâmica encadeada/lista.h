#include <stdlib.h>
#include <stdio.h>

typedef struct{
	char nSerie[20];
	char modelo[20];
} obj_b;

typedef struct NO {
	struct NO *prox;
	struct NO *ant;
	obj_b info;
} No;

typedef struct lista {
	No *inic;
	No *fim;
	int tam;
} Lista;

typedef struct {
	int tam;
	No *topo;
	int max;	
} Pilha;

typedef struct NO_PILHA{
	struct NO_PILHA *prox;
	Pilha  info;
} No_Pilha;

typedef struct {
	No_Pilha *inic;
	No_Pilha *fim;
} Fila;

//TAD LISTA
void cria_lista(Lista*);
int insere_na_lista(Lista*, obj_b);
int remover(Lista*, int, Fila*, int);
int brinquedo_caixa(Pilha*, No*, Fila*, int, int);
//remove_da_lista(i)
//vazia_lista()

//TAD PILHA
void cria_pilha(Pilha*, int);
int push(Pilha*, obj_b*);
obj_b top(Pilha*);
int tam(Pilha*);
int cheia_pilha(Pilha*);

//TAD FILA
void cria_fila(Fila*);
int insere_Fila(Fila*, Pilha*);
int remove_fila(Fila*, Pilha*);
int vazia_fila(Fila*);
void imprime_fila(Fila*);



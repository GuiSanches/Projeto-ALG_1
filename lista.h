#include <stdlib.h>
#include <stdio.h>

typedef int elem;

typedef struct NO {
	struct NO *prox;
	struct NO *ant;
	elem info;
} No;

typedef struct lista {
	No *inic;
	No *fim;
	int tam;
} Lista;

int CriaLista(Lista*);
int insere(Lista*, elem x);
int remover(Lista*, int);
void ApagaLista(Lista*);
int imprimeLista(Lista *);

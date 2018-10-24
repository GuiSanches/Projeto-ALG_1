#include "lista.h"
#include <stdio.h>
#include <string.h>

int main() {
	Lista LISTA;
	obj_b x;

	strcpy(x.modelo, "carro");
	x.nSerie = 0;

	cria_lista(&LISTA);

	for(i = 0; i < 5; i++) {
		insere_na_lista(&LISTA, x);		
		x.nSerie++;
	}

	for(i = 0; i < 5; i++) {
		printf("%d ",LISTA.elem[i]);
	}

	remove_da_lista(&LISTA, i);	

	return 0;
}
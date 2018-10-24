#include "lista.h"

int main() {
	int n;//numero de brinquedos
	int k;//intervalo
	int p;//capacidade da caixa
	obj_b brinquedo;
	Lista esteira;//esteira circular
	Fila Caixas;

	scanf("%d %d %d", &n, &k, &p);

	cria_lista(&esteira);
	cria_fila(&Caixas);	

	for(int i = 0; i < n; i++){
		scanf(" %s %s", brinquedo.nSerie, brinquedo.modelo);
		insere_na_lista(&esteira, brinquedo);
	}
	remover(&esteira, k, &Caixas, p);	
	imprime_fila(&Caixas);

	return 0;
}

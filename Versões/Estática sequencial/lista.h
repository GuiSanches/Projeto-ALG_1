#include <stdlib.h>

#define TamFila 1000
#define TamPilha 1000
#define TamLista 1000


typedef struct {
	int nSerie;
	char modelo[100];
} obj_b;

typedef struct {
	obj_b elem[TamLista];
	int ini, fim, qtd;
} Lista;

typedef struct {
	obj_b elem[TamPilha];
	int topo;
} Pilha;

typedef struct {
	Pilha elem[TamFila];
	int ini, fim, qtd;
} Fila;


/*void vazia_lista() {

}

void cheia_lista() {

}
*/



void cria_lista(Lista *L);// cria uma lista vazia;
void insere_na_lista(Lista *L, obj_b x);// insere um brinquedo (isto é, um struct com o número de série e o modelo do brinquedo) no final da lista;
obj_b remove_da_lista(Lista *L, int i);//: remove e retorna o brinquedo na posição i da lista;
/* vazia_lista()// retorna “true” se a lista estiver vazia; “false”, caso contrário; - 
 cheia_lista()// retorna “true” se a lista estiver cheia; “false”, caso contrário. DEVE EXISTIR APENAS PARA A IMPLEMENTAÇÃO ESTATICA.  
 
//Crie uma pilha para representar cada caixa de brinquedos. O TAD correspondente deve conter pelo menos as seguintes operações: - 
cria_pilha()// cria uma pilha vazia; - 
push(brinquedo)// insere um brinquedo na pilha/caixa, segundo a ordenação LIFO, em que o último a entrar é o primeiro a sair; - 
top()//: retorna o brinquedo no topo da pilha/caixa, sem removê-lo; - 
cheia_pilha()//: retorna “true” se o número de brinquedos for igual a p; “false”, caso contrário; 
 
//Crie uma fila de caixas de brinquedos, isto é, uma fila de pilhas. O TAD correspondente deve conter pelo menos as seguintes operações: - 
cria_fila()// cria uma fila vazia; - 
insere_na_fila(caixa)// insere uma caixa (isto é, uma pilha de brinquedos) na fila, segundo a ordenação FIFO, em que o primeiro a entrar é o primeiro a sair; - 
remove_fila()// remove uma caixa da fila; - 
vazia_fila()// retorna “true” se a fila estiver vazia; “false”, caso contrário; - 
cheia_fila()// retorna “true” se a fila estiver cheia; “false”, caso contrário. DEVE EXISTIR APENAS PARA A IMPLEMENTAÇÃO ESTATICA.
 */
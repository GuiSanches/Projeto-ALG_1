#define TamFila 100

typedef char elem;

typedef struct {
    int inicio, fim, total;
    elem vet[TamFila];
} Fila;

void cria_fila(Fila* f);
void esvazia_fila(Fila* f);
int estaCheia(Fila* f);
int estaVazia(Fila* f);
int entra(Fila* f, elem x);
int sai(Fila* f, elem* x);
int estaOrdenada(Fila* f);

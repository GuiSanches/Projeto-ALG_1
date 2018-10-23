#include "fila.h"

void cria_fila(Fila* f) {
    f->inicio = 0;
    f->fim = 0;
    f->total = 0;
    return;
}

void esvazia_fila(Fila* f) {
    cria_fila(f);
    return;
}

int estaCheia(Fila* f) {
    return f->total == TamFila;
}

int estaVazia(Fila* f) {
    if (f->total == 0)
        return 1;
    return 0;
}

int entra(Fila* f, elem x) {
    if (estaCheia(f))
        return 1;
    f->vet[f->fim] = x;
    f->total++;
    if (f->fim == TamFila-1)
        f->fim = 0;
    else
        f->fim++;
    return 0;
}

int sai(Fila* f, elem* x) {
    if (estaVazia(f))
        return 1;
    *x = f->vet[f->inicio];
    f->total--;
    if (f->inicio == TamFila-1)
        f->inicio = 0;
    else
        f->inicio++;
    return 0;
}

int estaOrdenada(Fila* f) {
    elem primeiro, segundo;
    int estaOrd = 1;
    int total_local = f->total;
    
    if (!estaVazia(f)) {
        sai(f, &primeiro);
        for (int i=0; i<total_local-1; i++) {
            sai(f, &segundo);
            if (primeiro > segundo)
                estaOrd = 0;
            entra(f, primeiro);
            primeiro = segundo;
        }
        entra(f, primeiro);
    }
    
    return estaOrd;
}

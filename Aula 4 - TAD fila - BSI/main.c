#include <stdio.h>
#include "fila.h"

int main(int argc, char* argv[]) {
    Fila f;
    elem x;
    
    cria_fila(&f);
    x=0;
    while(!entra(&f, x))
        x++;
    
    sai(&f,&x);
    entra(&f,x);
    
    if (estaOrdenada(&f))
        printf("A fila estah ordenada!\n");
    else
        printf("A fila NAO estah ordenada!\n");
    
    while(!sai(&f,&x))
        printf("%d\n", x);
    
    return 0;
}

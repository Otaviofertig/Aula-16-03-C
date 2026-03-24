#include <stdio.h>
#include "caixa.h"
#include <stdlib.h>

struct Caixa {
    int valor;
};

Caixa*criar_caixa(int valor_inicial) {
    Caixa *c;

    c = (Caixa *) malloc(sizeof(Caixa));
    if (c==NULL) {
    return NULL;
    }

    c->valor = valor_inicial;
    return c;
}
int ler_valor (Caixa *c) {
    if (c == NULL) {
        return -1;
    }

    return c->valor;
}

void escrever_valor(Caixa *c, int valor) {
    if ( c== NULL) {
        return;
    }

    c->valor = valor;
}

void destruir_caixa(Caixa *c) {
    if(c == NULL){
        return;
    }

    free(c);
}
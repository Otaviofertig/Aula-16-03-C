#include <stdio.h>
#include "caixa.h"

int main() {
    Caixa* c;

    c = criar_caixa(100);
    if (c == NULL) {
        printf("Erro ao criar caixa");
        return 1;
    }

    printf("Valor inicial: %d\n", ler_valor(c));
    escrever_valor(c,250);
    printf("Valor atualizado; %d\n", ler_valoor(c));
    
    destruir_caixa(c);
    return 0;
    }
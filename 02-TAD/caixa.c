#include <stdio.h>
#include <stdlib.h> // Necessário para malloc e free
#include "caixa.h"  // Importa o próprio contrato para garantir que as assinaturas batem

// A Revelação: Apenas o "Motor" sabe o que tem dentro da Caixa.
// Se precisarmos adicionar 'float peso' amanhã, o main.c nem fica sabendo!
struct Caixa {
    int valor;
};

// Construtor
Caixa* criar_caixa(int valor_inicial) {
    // 1. Aloca memória no Heap dinamicamente
    Caixa *c = (Caixa *) malloc(sizeof(Caixa));
    
    // 2. Proteção contra falta de memória RAM
    if (c == NULL) {
        return NULL;
    }

    // 3. Inicialização
    c->valor = valor_inicial;
    return c;
}

// Getter (Leitura)
int ler_valor(Caixa *c) {
    // Segurança máxima: se o ponteiro for nulo, retorna um código de erro genérico
    if (c == NULL) {
        return -1; 
    }
    return c->valor;
}

// Setter (Escrita)
void escrever_valor(Caixa *c, int valor) {
    if (c == NULL) {
        return;
    }
    c->valor = valor;
}

// Destrutor
void destruir_caixa(Caixa *c) {
    if(c == NULL){
        return;
    }
    // Libera a memória alocada no construtor para evitar Memory Leak
    free(c);
}

#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>

// Exercício 1: Estrutura do Nodo Duplo
typedef struct Nodo {
    int valor;
    struct Nodo *anterior;
    struct Nodo *proximo;
} Nodo;

// Exercício 2: Estrutura da Lista
typedef struct {
    Nodo *inicio;
    Nodo *fim;
    int tamanho;
} Lista;

// --- Protótipos das Funções ---

// Ex 1: Funções do Nodo
Nodo* criar_nodo(int valor);
int obter_valor(Nodo *nodo);
void definir_valor(Nodo *nodo, int valor);
Nodo* obter_anterior(Nodo *nodo);
Nodo* obter_proximo(Nodo *nodo);
void definir_anterior(Nodo *nodo, Nodo *anterior);
void definir_proximo(Nodo *nodo, Nodo *proximo);
void destruir_nodo(Nodo *nodo);

// Ex 2: Funções base da Lista
Lista* criar_lista();
int esta_vazia(Lista *lista);
int tamanho(Lista *lista);
void destruir_lista(Lista *lista);

// Ex 3 e 4: Inserções nas extremidades
int inserir_inicio(Lista *lista, int valor);
int inserir_fim(Lista *lista, int valor);

// Ex 5: Impressão
void imprimir_inicio_fim(Lista *lista);
void imprimir_fim_inicio(Lista *lista);

// Ex 6 e 7: Remoções nas extremidades
int remover_inicio(Lista *lista, int *valor_removido);
int remover_fim(Lista *lista, int *valor_removido);

// Ex 8: Busca
Nodo* buscar(Lista *lista, int valor);

// Ex 9: Inserção em posição específica
int inserir_posicao(Lista *lista, int valor, int posicao);

// Ex 10: Remoção por valor
int remover_valor(Lista *lista, int valor);

#endif
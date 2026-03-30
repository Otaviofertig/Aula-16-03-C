#include<stdio.h>
#include<stdlib.h>

typedef struct Nodo{
    int valor;
    struct Nodo* proximo;
} Nodo;

typedef struct {
    Nodo *inicio;
    Nodo *fim;
    int tamanho;
}Fila;

int main() {

    return 0;
}
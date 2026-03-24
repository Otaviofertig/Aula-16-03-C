#ifndef CAIXA_H
#define CAIXA_H

typedef struct Caixa_caixa;

Caixa* criar_caixa(int valor_inicial);
void destruir_caixa(Caixa* caixa);
void escrever_valor(Caixa* c, int valor);
int ler_valor(Caixa* c);

#endif
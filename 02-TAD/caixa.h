// Include Guards: Evitam que o arquivo seja incluído duplicadamente,
// o que causaria erro de "redefinição" no compilador.
#ifndef CAIXA_H
#define CAIXA_H

// O Segredo do TAD (Opaque Pointer): 
// Declaramos que existe uma struct chamada Caixa, mas NÃO dizemos 
// o que tem dentro dela. O Cliente (main) fica cego para os dados internos.
typedef struct Caixa Caixa;

// Assinaturas das funções (O Contrato)
Caixa* criar_caixa(int valor_inicial);
void destruir_caixa(Caixa* c);
void escrever_valor(Caixa* c, int valor);
int ler_valor(Caixa* c);

#endif

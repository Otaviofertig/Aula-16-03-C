#include <stdio.h>
#include <stdlib.h> // CORREÇÃO: Inclusão correta do cabeçalho (.h)

// Boa prática: usar (void) quando a função não recebe argumentos de linha de comando
int main(void) {
    int *vetor; // Ponteiro que guardará o endereço do bloco alocado no Heap
    int capacidade = 5;

    // ALOCAÇÃO DINÂMICA
    // Cálculo matemático: Tamanho = Capacidade * sizeof(int)
    // Se 'int' ocupa 4 bytes, estamos pedindo 20 bytes contíguos na memória.
    vetor = (int *) malloc(capacidade * sizeof(int));

    // TRATAMENTO DE ERRO: O malloc retorna NULL se a memória RAM estiver cheia
    if(vetor == NULL) {
        // stderr é o canal correto para mensagens de erro
        fprintf(stderr, "Erro critico: Falha ao alocar memoria.\n");
        return 1; // Encerra o programa indicando falha ao SO
    }

    // PROCESSAMENTO: Preenchendo o vetor
    for (int i = 0; i < capacidade; i++) {
        // A aritmética de ponteiros interna traduz vetor[i] para *(vetor + i)
        vetor[i] = (i + 1) * 10;
    }

    // SAÍDA DE DADOS
    printf("Conteudo do vetor: ");
    for (int i = 0; i < capacidade; i++) {
        printf("%d ", vetor[i]); // CORREÇÃO: Adicionado espaço para legibilidade
    }
    printf("\n"); // Pula linha após imprimir todo o vetor

    // GERENCIAMENTO DE MEMÓRIA
    // O que nasce no Heap (malloc), morre no Heap (free).
    free(vetor); // CORREÇÃO: Ponto e vírgula no final

    // SEGURANÇA: Prevenção contra "Dangling Pointers" (Ponteiros Soltos)
    // Depois de liberar a memória, o ponteiro ainda guarda o endereço antigo.
    // Forçamos ele a apontar para o 'vazio' para evitar uso indevido acidental.
    vetor = NULL; 

    return 0; // Sucesso
}

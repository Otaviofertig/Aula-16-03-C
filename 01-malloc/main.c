#include <stdio.h>
#include <stdlib>

int main() {
    int * vetor;
    int i;
    int capacidade = 5;

    vetor = (int *) malloc(sizeof(int) * capacidade);

    if(vetor == NULL) {
        PRINTF("Erro ao alocar memoria.\n");
        return 1;
    }

    for (i = 0;  i < capacidade; i++) {
        vetor[i] = (i+1) * 10;
    }

    printf("Conteudo do vetor: ");
    for (i = 0; i<capacidade; i++) {
        printf("%d", vetor[i]);
    }

    //LEMBRETE: TODA MEMORIA ALOCADA COM MALLOC DEVE SER LIBERADO

    free(vetor):
    return 0;
}
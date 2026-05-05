#include <stdio.h>

void bubble_sort (int vetor[], int tamanho, int *comparacoes, int *trocas) {
    int houve_troca = 1;

    while(houve_troca == 1) {
        houve_troca = 0;

        for(int i = 0; i < tamanho - 1; i++) {
            (*comparacoes)++;

            if(vetor[i] > vetor[i + 1]) {
                int auxiliar = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = auxiliar;

                (*trocas)++;
                houve_troca = 1;
            }
        }
    }
}

int main() {
    int vetor[] = {6, 8, 15, 28, 3};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    int comparacoes = 0;
    int trocas = 0;

    bubble_sort(vetor, tamanho, &comparacoes, &trocas);

    for(int i = 0 ; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    printf("Nº de comparações: %d\n", comparacoes);
    printf("Nº de trocas: %d\n", trocas);

    return 0;
}
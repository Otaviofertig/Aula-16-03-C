#include <stdio.h>

void insertionSort(int vetor[], int tamanho, int *comparacoes, int *trocas) {
    for(int i = 1; i < tamanho; i++) {
        int valor_atual = vetor[i];
        int j = i - 1;

        while(j >= 0) {
            (*comparacoes)++;
            
            if(vetor[j] > valor_atual) {
                vetor[j + 1] = vetor[j];
                (*trocas)++;
                j--;
            } else {
                break;
            }
        }
        
        vetor[j + 1] = valor_atual;
        if(j + 1 != i) {
            (*trocas)++;
        }
    }
}

int main() {
    int vetor[] = {6, 8, 15, 28, 3};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    int comparacoes = 0;
    int trocas = 0;

    insertionSort(vetor, tamanho, &comparacoes, &trocas);

    for(int i = 0 ; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    printf("Nº de comparações: %d\n", comparacoes);
    printf("Nº de trocas: %d\n", trocas);

    return 0;
}
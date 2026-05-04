#include <stdio.h>

void bubble_sort (int vetor[], int tamanho) {
    int houve_troca = 1;
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    while(houve_troca == 1) {
        houve_troca = 0;

        for(int i=0; i < tamanho ; i++) {
            if(vetor[i] > vetor[i + 1]) {
                int auxiliar = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = auxiliar;

                houve_troca = 1;
            }
        }
    }
}

int main() {
    int vetor[] = {6,8,15,28,3};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    bubble_sort(vetor);

    for(int i=0 ; i<tamanho; i++) {
        printf("%d", vetor[i])
    }
    return 0;
}
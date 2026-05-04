/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

void bubble_sort (int vetor[], int tamanho) {
    int houve_troca = 1;
   

    while(houve_troca == 1) {
        houve_troca = 0;

        for(int i=0; i < tamanho -1 ; i++) {
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

    bubble_sort(vetor, tamanho);

    for(int i=0 ; i<tamanho; i++) {
        printf("%d", vetor[i]);
    }
    return 0;
}
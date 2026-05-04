#include <stdio.h>


int busca_binaria(int vetor[], int tamanho, int valor_procurado) {
    int inicio = 0;
    int fim = tamanho -1;

    while(inicio <= fim){
        int meio = (inicio+fim) /2;

        printf("inicio=%d, meio=%d, fim=%d, valor_procurado=%d\n", inicio, meio, fim, valor_procurado);
        
        if (vetor[meio] == valor_procurado)
        return meio;
    }

    if (valor_procurado < vetor[meio]) {
        fim = meio -1; 
    }else {
        inicio = meio +1;
    }

    return -1;
}

int main() {
    int dados[] = {3, 6, 8, 99, 100};
    int tamanho = 100;
    int valor = 69;

    int posicao = busca_binaria(dados, tamanho, valor_procurado);

    if (posicao == -1){
        printf("O valor não foi encontrado!!!\n");
    }else{
        printf("O valor foi encontrado!!! Na posição%d\n", valor_procurado, posicao);
    }

    printf("")
}
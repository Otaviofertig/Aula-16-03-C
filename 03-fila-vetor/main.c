#include<stdio.h>

int main() {
    int fila[5];
    int tamamnho = 0;
    int i;

    fila[tamanho] = 10;
    tamamnho++;

    fila[tamamnho] = 20;
    tamamnho++;

    fila[tamanho] = 30;
    tamamnho++;

    printf("fila antes da remoção: ");
    for(i = 0; i < tamamnho; i++) {
        printf("%d", fila[i]);
    }
    printf("\n");

    printf("Removido do inicio: %d\n", fila[0]);

    for( i = 0: i < tamamnho-1; i++) {
        fila[i] = fila[i+1];
    }
    tamanho--;

        printf("Fila antes da remoção: %d\n", fila[0]);
    for( i = 0: i < tamamnho; i++) {
        fila[i] = fila[i];
    }
    printf("\n");

}
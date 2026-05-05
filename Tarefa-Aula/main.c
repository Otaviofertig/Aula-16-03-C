#include <stdio.h>
#include <string.h> 

// 1. Criação da struct Cliente
typedef struct {
    int codigo;
    char nome[50];
    char telefone[15];
} Cliente;

// 2. Seu Insertion Sort EXATAMENTE com a sua lógica base
void insertionSort(Cliente vetor[], int tamanho, int *comparacoes, int *trocas) {
    for(int i = 1; i < tamanho; i++) {
        Cliente valor_atual = vetor[i]; // Agora guardamos a struct inteira
        int j = i - 1;

        while(j >= 0) {
            (*comparacoes)++;
            
            // Fiel à sua estrutura, apenas usando strcmp no lugar do sinal ">"
            if(strcmp(vetor[j].nome, valor_atual.nome) > 0) {
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


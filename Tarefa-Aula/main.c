#include <stdio.h>
#include <string.h> 

typedef struct {
    int codigo;
    char nome[50];
    char telefone[15];
} Cliente;

void insertionSort(Cliente vetor[], int tamanho, int *comparacoes, int *trocas) {
    for(int i = 1; i < tamanho; i++) {
        Cliente valor_atual = vetor[i];
        int j = i - 1;

        while(j >= 0) {
            (*comparacoes)++;
            
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

void buscaSequencial(Cliente vetor[], int tamanho, char telefoneProcurado[]) {
    int encontrado = 0;
    for(int i = 0; i < tamanho; i++) {
        
        if(strcmp(vetor[i].telefone, telefoneProcurado) == 0) {
            printf("-> Cliente Encontrado! Codigo: %d | Nome: %s\n\n", vetor[i].codigo, vetor[i].nome);
            encontrado = 1;
            break;
        }
    }
    if(encontrado == 0) {
        printf("-> Telefone %s nao encontrado.\n\n", telefoneProcurado);
    }
}

int main() {
    
    Cliente clientes[10] = {
        {8, "Marcos Silva", "8888-8888"},
        {3, "Ana Costa", "3333-3333"},
        {10, "Zeca Pagodinho", "0000-0000"},
        {1, "Bianca Lima", "1111-1111"},
        {5, "Carlos Souza", "5555-5555"},
        {7, "Fernanda Reis", "7777-7777"},
        {2, "Daniel Alves", "2222-2222"},
        {9, "Paula Moraes", "9999-9999"},
        {4, "Joao Santos", "4444-4444"},
        {6, "Lucas Pereira", "6666-6666"}
    };
    
    int tamanho = 10;
    int comparacoes = 0;
    int trocas = 0;

    
    insertionSort(clientes, tamanho, &comparacoes, &trocas);

    printf("--- ORDENADO POR NOME (USANDO STRCMP) ---\n");
    for(int i = 0 ; i < tamanho; i++) {
        printf("Codigo: %02d | Nome: %-15s | Tel: %s\n", clientes[i].codigo, clientes[i].nome, clientes[i].telefone);
    }
    printf("\n");

    printf("N de comparacoes: %d\n", comparacoes);
    printf("N de trocas: %d\n\n", trocas);

    printf("--- BUSCA SEQUENCIAL ---\n");
    printf("Procurando '7777-7777'...\n");
    buscaSequencial(clientes, tamanho, "7777-7777");

    return 0;
}


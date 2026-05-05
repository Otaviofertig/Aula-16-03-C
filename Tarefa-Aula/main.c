#include <stdio.h>
#include <string.h> 

typedef struct {
    int codigo;
    char nome[50];
    char telefone[15];
} Cliente;


void insertionSortCodigo(Cliente vetor[], int tamanho) {
    for(int i = 1; i < tamanho; i++) {
        Cliente valor_atual = vetor[i];
        int j = i - 1;
    
        while(j >= 0 && vetor[j].codigo > valor_atual.codigo) {
            vetor[j + 1] = vetor[j];
            j--;
        }
        
        vetor[j + 1] = valor_atual;
    }
}

void insertionSortNome(Cliente vetor[], int tamanho) {
    for(int i = 1; i < tamanho; i++) {
        Cliente valor_atual = vetor[i];
        int j = i - 1;

       
        while(j >= 0 && strcmp(vetor[j].nome, valor_atual.nome) > 0) {
            vetor[j + 1] = vetor[j];
            j--;
        }
        
        vetor[j + 1] = valor_atual;
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


void imprimirClientes(Cliente vetor[], int tamanho) {
    for(int i = 0 ; i < tamanho; i++) {
        printf("Codigo: %02d | Nome: %-15s | Tel: %s\n", vetor[i].codigo, vetor[i].nome, vetor[i].telefone);
    }
    printf("\n");
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

    printf("--- 1. VETOR ORIGINAL DESORDENADO ---\n");
    imprimirClientes(clientes, tamanho);

    printf("--- 2. ORDENADO POR CODIGO (REQUISITO 3) ---\n");
    insertionSortCodigo(clientes, tamanho);
    imprimirClientes(clientes, tamanho);

    printf("--- 3. ORDENADO POR NOME (DESAFIO AVANCADO) ---\n");
    insertionSortNome(clientes, tamanho);
    imprimirClientes(clientes, tamanho);

    printf("--- 4. BUSCA SEQUENCIAL (DESAFIO AVANCADO) ---\n");
    printf("Procurando '7777-7777'...\n");
    buscaSequencial(clientes, tamanho, "7777-7777");

    return 0;
}
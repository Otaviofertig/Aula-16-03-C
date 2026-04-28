#include <stdio.h>
#include <string.h>

#define TOTAL_CLIENTES 6

typedef struct {
    int codigo;
    char nome[50];
    char telefone[20];
} Cliente;

int buscar_cliente_por_codigo(Cliente clientes[], int tamanho, int codigo) {
    for (int i = 0; i < tamanho; i++) {
        if (clientes[i].codigo == codigo) {
            return i;
        }
    }
    return -1;
}

int buscar_cliente_por_nome(Cliente clientes[], int tamanho, char nome[]) {
    for (int i = 0; i < tamanho; i++) {
        if (strcmp(clientes[i].nome, nome) == 0) {
            return i;
        }
    }
    return -1;
}

int buscar_cliente_por_telefone(Cliente clientes[], int tamanho, char telefone[]) {
    for (int i = 0; i < tamanho; i++) {
        if (strcmp(clientes[i].telefone, telefone) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    Cliente clientes[TOTAL_CLIENTES] = {
        {101, "Ana", "99999-1111"},
        {205, "Bruno", "99999-2222"},
        {310, "Carla", "99999-3333"},
        {412, "Diego", "99999-4444"},
        {578, "Eduarda", "99999-5555"},
        {699, "Felipe", "99999-6666"}
    };

    int posicao;

    int cod_busca = 412;
    posicao = buscar_cliente_por_codigo(clientes, TOTAL_CLIENTES, cod_busca);
    if (posicao != -1) {
        printf("Cliente encontrado por codigo: %s\n", clientes[posicao].nome);
    } else {
        printf("Cliente nao encontrado pelo codigo informado.\n");
    }

    char nome_busca[] = "Carla";
    posicao = buscar_cliente_por_nome(clientes, TOTAL_CLIENTES, nome_busca);
    if (posicao != -1) {
        printf("Cliente encontrado por nome: nome %d\n", clientes[posicao].nome);
    } else {
        printf("Cliente nao encontrado pelo nome informado.\n");
    }

    int cod_erro = 999;
    posicao = buscar_cliente_por_codigo(clientes, TOTAL_CLIENTES, cod_erro);
    if (posicao != -1) {
        printf("Cliente encontrado por codigo: %s\n", clientes[posicao].codigo);
    } else {
        printf("Cliente nao encontrado pelo codigo informado.\n");
    }

    char tel_busca[] = "99999-5555";
    posicao = buscar_cliente_por_telefone(clientes, TOTAL_CLIENTES, tel_busca);
    if (posicao != -1) {
        printf("Cliente encontrado por telefone: Nome: %s, Codigo: %d\n", clientes[posicao].nome, clientes[posicao].codigo);
    } else {
        printf("Cliente nao encontrado pelo telefone informado.\n");
    }

    return 0;
}
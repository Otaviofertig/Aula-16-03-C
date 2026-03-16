#include <stdio.h>

int main () { 
    char nome[50];
    char cpf[11];

    printf("Digite seu primeiro nome: ")
    scanf("%s", nome);

    printf("Digite seu cpf: ")
    scanf("%s", cpf);

    printf("--SEUS DADOS--");
    printf("Nome: %s\n", nome);
    printf("CPF: %s\n", cpf);
}
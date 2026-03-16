#include <stdio.h>

struct Pessoa {
    char nome[50];
    char sexo;
    char cpf[13];
    float peso, altura;
    int dia, mes, ano;
};

    int main() {

    struct Pessoa strPessoa;
    
    printf("Digite seu primeiro nome: ");
    scanf("%s", strPessoa.nome);

    printf("Digite seu cpf: ");
    scanf("%s", strPessoa.cpf);

    printf("Sexo (m/f): ");
    scanf(" %c", &strPessoa.sexo); 

    printf("Data de nascimento\n");
    printf("Dia: ");
    scanf("%d", &strPessoa.dia);

    printf("Mes: ");
    scanf("%d", &strPessoa.mes);

    printf("Ano: ");
    scanf("%d", &strPessoa.ano);

    printf("Peso: ");
    scanf("%f", &strPessoa.peso); 

    printf("Altura: ");
    scanf("%f", &strPessoa.altura); 

   
    printf("\n--SEUS DADOS--\n"); 
    printf("CPF: %s\n", strPessoa.cpf);
    printf("Sexo: %c\n", strPessoa.sexo);
    printf("Nascimento: %02d/%02d/%d\n", strPessoa.dia, strPessoa.mes, strPessoa.ano); 
    printf("Peso: %.2f\n", strPessoa.peso);
    printf("Altura: %.2f\n", strPessoa.altura);

    return 0;
}
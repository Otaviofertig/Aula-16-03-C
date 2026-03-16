#include <stdio.h>

int main () {
    char nome[50];
    char sexo;
    char cpf[13];
    float peso, altura;
    int dia, mes, ano;

    
    printf("Digite seu primeiro nome: ");
    scanf("%s", nome);

    printf("Digite seu cpf: ");
    scanf("%s", cpf);

    printf("Sexo (m/f): ");
    scanf(" %c", &sexo); 

    printf("Data de nascimento\n");
    printf("Dia: ");
    scanf("%d", &dia);

    printf("Mes: ");
    scanf("%d", &mes);

    printf("Ano: ");
    scanf("%d", &ano);

    printf("Peso: ");
    scanf("%f", &peso); 

    printf("Altura: ");
    scanf("%f", &altura); 

   
    printf("\n--SEUS DADOS--\n"); 
    printf("CPF: %s\n", cpf);
    printf("Sexo: %c\n", sexo);
    printf("Nascimento: %02d/%02d/%d\n", dia, mes, ano); 
    printf("Peso: %.2f\n", peso);
    printf("Altura: %.2f\n", altura);

    return 0;
}
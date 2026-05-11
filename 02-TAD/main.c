#include <stdio.h>
#include "caixa.h" // O main conhece APENAS o contrato, não sabe o que é o 'int valor' interno

int main(void) {
    Caixa* c; // Ponteiro opaco. O main não sabe o tamanho de 'Caixa' na memória.

    // Instanciação
    c = criar_caixa(100);
    
    // Tratamento de Erro vital
    if (c == NULL) {
        fprintf(stderr, "Erro critico: Nao foi possivel criar a caixa.\n");
        return 1;
    }

    // Uso seguro das operações via funções (Encapsulamento)
    // Nota: O main NÃO PODE fazer 'c->valor = 250;'. O compilador bloquearia!
    printf("Valor inicial: %d\n", ler_valor(c));
    
    escrever_valor(c, 250);
    
    // Correção: ler_valor (estava ler_valoor) e ajuste do texto
    printf("Valor atualizado: %d\n", ler_valor(c)); 
    
    // Limpeza da memória
    destruir_caixa(c);
    
    // Prevenção de Dangling Pointer (Boa prática)
    c = NULL;

    return 0;
}

#include <stdio.h>
#include "lista.h"

int main() {
    printf("=== Testando a Lista Duplamente Encadeada ===\n");
    Lista *minha_lista = criar_lista();

    // Testando inserções
    inserir_inicio(minha_lista, 20);
    inserir_inicio(minha_lista, 10);
    inserir_fim(minha_lista, 40);
    
    // Testando inserção no meio (Ex 9) - Lista atual: 10 20 40
    inserir_posicao(minha_lista, 30, 2); 
    
    // Ex 5: Verificando as impressões
    imprimir_inicio_fim(minha_lista); // Esperado: 10 20 30 40
    imprimir_fim_inicio(minha_lista); // Esperado: 40 30 20 10

    // Ex 6 e 7: Remoções
    int removido;
    remover_inicio(minha_lista, &removido);
    printf("Removido do inicio: %d\n", removido); // Esperado: 10

    remover_fim(minha_lista, &removido);
    printf("Removido do fim: %d\n", removido); // Esperado: 40
    
    // Ex 10: Remoção por valor (A lista agora tem 20 30)
    inserir_fim(minha_lista, 50); // Fica: 20 30 50
    printf("Removendo o valor 30...\n");
    remover_valor(minha_lista, 30);
    imprimir_inicio_fim(minha_lista); // Esperado: 20 50

    // Ex 8: Busca
    Nodo *resultado = buscar(minha_lista, 50);
    if (resultado != NULL) {
        printf("Valor %d encontrado na lista!\n", obter_valor(resultado));
    }

    // Limpeza da memória
    destruir_lista(minha_lista);
    printf("Lista destruida com sucesso. Fim do programa.\n");

    return 0;
}
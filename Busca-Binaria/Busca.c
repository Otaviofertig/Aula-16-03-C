#include <stdio.h>

// Função de Busca Binária
// Recebe um ponteiro para o vetor (int *), tamanho e o alvo.
int busca_binaria(int *vetor, int tamanho, int valor_procurado) {
    int inicio = 0;
    int fim = tamanho - 1;

    while (inicio <= fim) {
        // CÁLCULO SEGURO: Evita overflow se 'inicio' e 'fim' forem números muito grandes.
        // É matematicamente equivalente a (inicio + fim) / 2
        int meio = inicio + (fim - inicio) / 2;

        // Printf para debug (uma boa prática em testes, remova em produção)
        printf("[Debug] inicio=%d, meio=%d, fim=%d\n", inicio, meio, fim);

        // Caso 1: Acertamos o alvo na mosca!
        if (vetor[meio] == valor_procurado) {
            return meio;
        }

        // Caso 2: Atualização dos limites (AGORA DENTRO DO WHILE)
        if (valor_procurado < vetor[meio]) {
            // O alvo é menor que o meio, descartamos a metade superior
            fim = meio - 1; 
        } else {
            // O alvo é maior que o meio, descartamos a metade inferior
            inicio = meio + 1;
        }
    }

    // Se o laço terminou e não achou, retorna -1
    return -1;
}

int main(void) {
    // Vetor já ORDENADO (Regra número 1 da busca binária)
    int dados[] = {3, 6, 8, 99, 100};
    
    // SEGURANÇA: Calculando o tamanho exato do vetor dinamicamente.
    // Pega o tamanho total em bytes do vetor e divide pelo tamanho em bytes de 1 elemento.
    int tamanho = sizeof(dados) / sizeof(dados[0]); 
    
    int valor_procurado = 69; // Vamos tentar procurar um valor que não existe

    // Chamada da função
    int posicao = busca_binaria(dados, tamanho, valor_procurado);

    // Tratamento de Erro / Resultado
    if (posicao == -1) {
        printf("Resultado: O valor %d NAO foi encontrado no vetor.\n", valor_procurado);
    } else {
        printf("Resultado: O valor %d foi encontrado na posicao %d!\n", valor_procurado, posicao);
    }

    return 0; // Código de saída indicando sucesso ao Sistema Operacional
}

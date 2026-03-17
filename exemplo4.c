#include <stdio.h>

int main() {
    int x = 10;
    int *p;

    p = &x;

    printf("Valor de x: %d\n", x);
    printf("Enedreço de x: %p\n", &x);
    printf("Valor usando o ponteiro: %d\n", *p);

    int *p2;

    p2  = (int *) malloc(sizeof(int));

    *p2 = 10;

    printf("Valor guardado: %d\n, *p2");
    printf("Endereço de memória: %p\n", p2);

    free(p2);

    int *vetor;
    int n = 5;

    vetor = malloc(n * sizeof(int));

    return 0;
}
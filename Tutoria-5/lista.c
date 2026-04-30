#include "lista.h"

// ============================================================================
// EXERCÍCIO 1: Manipulação do Nodo
// ============================================================================
Nodo* criar_nodo(int valor) {
    Nodo *novo = (Nodo*) malloc(sizeof(Nodo));
    if (novo != NULL) {
        novo->valor = valor;
        novo->anterior = NULL;
        novo->proximo = NULL;
    }
    return novo; // Retorna o nodo criado ou NULL se falhar a alocação
}

int obter_valor(Nodo *nodo) { return nodo->valor; }
void definir_valor(Nodo *nodo, int valor) { nodo->valor = valor; }
Nodo* obter_anterior(Nodo *nodo) { return nodo->anterior; }
Nodo* obter_proximo(Nodo *nodo) { return nodo->proximo; }
void definir_anterior(Nodo *nodo, Nodo *anterior) { nodo->anterior = anterior; }
void definir_proximo(Nodo *nodo, Nodo *proximo) { nodo->proximo = proximo; }

void destruir_nodo(Nodo *nodo) {
    free(nodo); // Libera a memória alocada para o nodo
}

// ============================================================================
// EXERCÍCIO 2: Base da Lista Duplamente Encadeada
// ============================================================================
Lista* criar_lista() {
    Lista *lista = (Lista*) malloc(sizeof(Lista));
    if (lista != NULL) {
        lista->inicio = NULL;
        lista->fim = NULL;
        lista->tamanho = 0;
    }
    return lista;
}

int esta_vazia(Lista *lista) {
    return lista->tamanho == 0;
}

int tamanho(Lista *lista) {
    return lista->tamanho;
}

void destruir_lista(Lista *lista) {
    int lixo;
    // Removemos todos os elementos até a lista ficar vazia
    while (!esta_vazia(lista)) {
        remover_inicio(lista, &lixo);
    }
    free(lista); // Libera a estrutura da lista
}

// ============================================================================
// EXERCÍCIO 3: Inserção no Início
// ============================================================================
int inserir_inicio(Lista *lista, int valor) {
    Nodo *novo = criar_nodo(valor);
    if (novo == NULL) return 0; // Falha na alocação

    if (esta_vazia(lista)) {
        lista->fim = novo; // Se está vazia, o novo é também o fim
    } else {
        definir_proximo(novo, lista->inicio);
        definir_anterior(lista->inicio, novo);
    }
    
    lista->inicio = novo; // Atualiza o ponteiro de início da lista
    lista->tamanho++;
    return 1; // Sucesso
}

// ============================================================================
// EXERCÍCIO 4: Inserção no Fim
// ============================================================================
int inserir_fim(Lista *lista, int valor) {
    Nodo *novo = criar_nodo(valor);
    if (novo == NULL) return 0;

    if (esta_vazia(lista)) {
        lista->inicio = novo; // Se está vazia, o novo é também o início
    } else {
        definir_anterior(novo, lista->fim);
        definir_proximo(lista->fim, novo);
    }
    
    lista->fim = novo; // Atualiza o ponteiro de fim da lista
    lista->tamanho++;
    return 1;
}

// ============================================================================
// EXERCÍCIO 5: Impressão Bidirecional
// ============================================================================
void imprimir_inicio_fim(Lista *lista) {
    Nodo *atual = lista->inicio;
    printf("Início para fim: ");
    while (atual != NULL) {
        printf("%d ", obter_valor(atual));
        atual = obter_proximo(atual);
    }
    printf("\n");
}

void imprimir_fim_inicio(Lista *lista) {
    Nodo *atual = lista->fim;
    printf("Fim para início: ");
    while (atual != NULL) {
        printf("%d ", obter_valor(atual));
        atual = obter_anterior(atual);
    }
    printf("\n");
}

// ============================================================================
// EXERCÍCIO 6: Remoção do Início
// ============================================================================
int remover_inicio(Lista *lista, int *valor_removido) {
    if (esta_vazia(lista)) return 0; // Erro: Lista vazia

    Nodo *nodo_remover = lista->inicio;
    *valor_removido = obter_valor(nodo_remover);

    lista->inicio = obter_proximo(nodo_remover); // O segundo passa a ser o primeiro

    if (lista->inicio == NULL) {
        lista->fim = NULL; // A lista ficou vazia
    } else {
        definir_anterior(lista->inicio, NULL); // Corta a ligação com o nodo removido
    }

    destruir_nodo(nodo_remover);
    lista->tamanho--;
    return 1;
}

// ============================================================================
// EXERCÍCIO 7: Remoção do Fim
// ============================================================================
int remover_fim(Lista *lista, int *valor_removido) {
    if (esta_vazia(lista)) return 0;

    Nodo *nodo_remover = lista->fim;
    *valor_removido = obter_valor(nodo_remover);

    lista->fim = obter_anterior(nodo_remover); // O penúltimo passa a ser o último

    if (lista->fim == NULL) {
        lista->inicio = NULL; // A lista ficou vazia
    } else {
        definir_proximo(lista->fim, NULL);
    }

    destruir_nodo(nodo_remover);
    lista->tamanho--;
    return 1;
}

// ============================================================================
// EXERCÍCIO 8: Busca por Valor
// ============================================================================
Nodo* buscar(Lista *lista, int valor) {
    Nodo *atual = lista->inicio;
    while (atual != NULL) {
        if (obter_valor(atual) == valor) {
            return atual; // Encontrou
        }
        atual = obter_proximo(atual);
    }
    return NULL; // Não encontrou
}

// ============================================================================
// EXERCÍCIO 9: Inserção em Posição Específica
// ============================================================================
int inserir_posicao(Lista *lista, int valor, int posicao) {
    if (posicao < 0 || posicao > tamanho(lista)) return 0; // Posição inválida

    if (posicao == 0) return inserir_inicio(lista, valor);
    if (posicao == tamanho(lista)) return inserir_fim(lista, valor);

    // Inserção no meio (precisamos encontrar a posição)
    Nodo *novo = criar_nodo(valor);
    if (novo == NULL) return 0;

    Nodo *atual = lista->inicio;
    for (int i = 0; i < posicao; i++) {
        atual = obter_proximo(atual);
    }

    // Ajusta os 4 ponteiros
    Nodo *nodo_anterior = obter_anterior(atual);
    
    definir_proximo(novo, atual);
    definir_anterior(novo, nodo_anterior);
    
    definir_proximo(nodo_anterior, novo);
    definir_anterior(atual, novo);

    lista->tamanho++;
    return 1;
}

// ============================================================================
// EXERCÍCIO 10: Remoção por Valor
// ============================================================================
int remover_valor(Lista *lista, int valor) {
    Nodo *alvo = buscar(lista, valor);
    if (alvo == NULL) return 0; // Valor não encontrado

    int lixo; // Variável para ignorar o valor retornado nas funções auxiliares
    
    // Se o alvo for o início ou o fim, reaproveitamos as funções já criadas
    if (alvo == lista->inicio) return remover_inicio(lista, &lixo);
    if (alvo == lista->fim) return remover_fim(lista, &lixo);

    // Remoção no meio
    Nodo *nodo_anterior = obter_anterior(alvo);
    Nodo *nodo_proximo = obter_proximo(alvo);

    definir_proximo(nodo_anterior, nodo_proximo);
    definir_anterior(nodo_proximo, nodo_anterior);

    destruir_nodo(alvo);
    lista->tamanho--;
    return 1;
}
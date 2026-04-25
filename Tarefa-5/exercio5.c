
#include <stdio.h>
#include <stdlib.h>

typedef struct DNode_ DNode;

struct DNode_ {
    int info;
    DNode *next;
    DNode *previous;
};

typedef struct DLIST_ {
    DNode *head;
    DNode *tail;    
    int size;
}DList;

DList* create_list() {
    DList *list = (DList*) malloc(sizeof(DList));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

void insert_head(DList *list, int value) {
    DNode *new_node = (DNode*) malloc(sizeof(DNode));
    new_node->info = value;
    new_node->previous = NULL;
    new_node->next = list->head;

    if (list->head != NULL) {
        list->head->previous = new_node;
    }
    list->head = new_node;

    if (list->tail == NULL) {
        list->tail = new_node;
    }
    list->size++;
}

void insert_tail(DList *list, int value) {
    DNode *new_node = (DNode*) malloc(sizeof(DNode));
    new_node->info = value;
    new_node->next = NULL;
    new_node->previous = list->tail;

    
    if (list->tail != NULL) {
        list->tail->next = new_node;
    }

    
    list->tail = new_node;
    if (list->head == NULL) {
        list->head = new_node;
    }
    list->size++;
}

// Retorna 1 se o paciente foi promovido com sucesso, e 0 se falhar
int promover_paciente(DList *list, int id) {
    if (list == NULL || list->head == NULL) return 0;

    // PASSO 1: Busca
    DNode *atual = list->head;
    while (atual != NULL && atual->info != id) {
        atual = atual->next;
    }

    // Se não encontrar o paciente, encerra a função
    if (atual == NULL) return 0; 

    // Validação extra: Se o paciente já é o Head (topo), não precisamos fazer nada!
    if (atual == list->head) return 1; 

    // PASSO 2: Guarda a Informação
    int id_salvo = atual->info;

    // PASSO 3: Remoção (Isolando e apagando o nó atual)
    // O vizinho de trás aponta para a frente
    if (atual->previous != NULL) {
        atual->previous->next = atual->next;
    }
    
    // O vizinho da frente aponta para trás
    if (atual->next != NULL) {
        atual->next->previous = atual->previous;
    } else {
        // Se era o Tail, o novo Tail passa a ser o anterior
        list->tail = atual->previous; 
    }

    free(atual);   // Apaga o nó antigo com segurança
    list->size--;  // Diminui o tamanho (pois ele será somado novamente na inserção)

    // PASSO 4: Inserção no Head
    insert_head(list, id_salvo);

    return 1; // Sucesso!
}
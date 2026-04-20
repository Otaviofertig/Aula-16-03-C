#include <stdio.h>
#include <stdlib.h>

typedef struct DNode_ DNode {
    int info;
    DNode *next;
    DNode *previous;
}

int main () {

    DNode *node1 = (DNode*) malloc(sizeof(DNode));
    DNode *node2 = (DNode*) malloc(sizeof(DNode));
    DNode *node3 = (DNode*) malloc(sizeof(DNode));

    node1->info = 10;
    node2->info = 20;
    node3->info = 30;

    node1->previous = NULL;
    node1->next = node2;

    node2->previous = node1;
    node2->next = node3;

    node3->previous = node2;
    node3->next = NULL;
}
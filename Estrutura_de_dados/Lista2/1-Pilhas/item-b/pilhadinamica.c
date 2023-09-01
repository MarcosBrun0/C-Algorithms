#include "pilhadinamica.h"
#include <stdlib.h>
#include <stdio.h>
Pilha* criarPilha() {
    Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
    pilha->topo = NULL;
    return pilha;
}

void destruirPilha(Pilha* pilha) {
    while (!vazia(pilha)) {
        desempilhar(pilha);
    }
    free(pilha);
}

int vazia(Pilha* pilha) {
    return (pilha->topo == NULL);
}

void empilhar(Pilha* pilha, int elemento) {
    Node* novoNo = (Node*)malloc(sizeof(Node));
    novoNo->elemento = elemento;
    novoNo->proximo = pilha->topo;
    pilha->topo = novoNo;
}

int desempilhar(Pilha* pilha) {
    if (vazia(pilha)) {
        printf("Pilha vazia. Impossível desempilhar elemento.\n");
        return -1; // ou outra indicação de erro
    }
    Node* noRemovido = pilha->topo;
    int elemento = noRemovido->elemento;
    pilha->topo = noRemovido->proximo;
    free(noRemovido);
    return elemento;
}

int topo(Pilha* pilha) {
    if (vazia(pilha)) {
        printf("Pilha vazia. Topo indefinido.\n");
        return -1; // ou outra indicação de erro
    }
    return pilha->topo->elemento;
}

#ifndef PILHA_H
#define PILHA_H

typedef struct Node {
    int elemento;
    struct Node* proximo;
} Node;

typedef struct {
    Node* topo;
} Pilha;

Pilha* criarPilha();
void destruirPilha(Pilha* pilha);
int vazia(Pilha* pilha);
void empilhar(Pilha* pilha, int elemento);
int desempilhar(Pilha* pilha);
int topo(Pilha* pilha);

#endif /* PILHA_H */

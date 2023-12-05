//
// Created by Marcos Bruno Campos on 27/11/23.
//

#include "B-tree.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ORDER 7

// Estrutura de um nó da B-tree
struct BTreeNode {
    int *keys;          // Array de chaves
    struct BTreeNode **children;  // Array de ponteiros para filhos
    int numKeys;        // Número atual de chaves
    int isLeaf;         // Indica se o nó é uma folha
};

// Função para criar um novo nó
struct BTreeNode *createNode(int leaf) {
    struct BTreeNode *newNode = (struct BTreeNode *)malloc(sizeof(struct BTreeNode));
    newNode->keys = (int *)malloc(sizeof(int) * (ORDER - 1));
    newNode->children = (struct BTreeNode **)malloc(sizeof(struct BTreeNode *) * ORDER);
    newNode->numKeys = 0;
    newNode->isLeaf = leaf;
    return newNode;
}

// Função para inserir uma chave na B-tree
struct BTreeNode *insert(struct BTreeNode *root, int key);

// Função para remover uma chave da B-tree
struct BTreeNode *removeKey(struct BTreeNode *root, int key);

// Função para buscar uma chave na B-tree
int search(struct BTreeNode *root, int key);

// Função para imprimir a B-tree
void printTree(struct BTreeNode *root, int level);

// Função para liberar a memória alocada para a B-tree
void freeTree(struct BTreeNode *root);

int main() {
    struct BTreeNode *root = NULL;
    srand(time(NULL));

    // Preenche a B-tree com 100 números aleatórios
    for (int i = 0; i < 100; i++) {
        int randomKey = rand() % 1000 + 1;  // Números aleatórios de 1 a 1000
        root = insert(root, randomKey);
    }

    int choice, key;

    do {
        // Exibe o menu
        printf("\nMenu:\n");
        printf("1. Inserir chave\n");
        printf("2. Remover chave\n");
        printf("3. Buscar chave\n");
        printf("4. Imprimir árvore\n");
        printf("5. Sair\n");

        // Solicita a escolha do usuário
        printf("Escolha: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Inserir chave
                printf("Digite a chave a ser inserida: ");
                scanf("%d", &key);
                root = insert(root, key);
                break;
            case 2:
                // Remover chave
                printf("Digite a chave a ser removida: ");
                scanf("%d", &key);
                root = removeKey(root, key);
                break;
            case 3:
                // Buscar chave
                printf("Digite a chave a ser buscada: ");
                scanf("%d", &key);
                if (search(root, key)) {
                    printf("Chave encontrada na árvore.\n");
                } else {
                    printf("Chave não encontrada na árvore.\n");
                }
                break;
            case 4:
                // Imprimir árvore
                printTree(root, 0);
                break;
            case 5:
                // Sair
                break;
            default:
                printf("Escolha inválida. Tente novamente.\n");
        }

    } while (choice != 5);

    // Libera a memória alocada para a B-tree antes de sair
    freeTree(root);

    return 0;
}

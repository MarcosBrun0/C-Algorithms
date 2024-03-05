// avl_tree.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "WordCount.h"

// Função auxiliar para obter a altura de um nó
int getHeight(struct AVLNode *node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}

// Função auxiliar para calcular o fator de balanceamento de um nó
int getBalance(struct AVLNode *node) {
    if (node == NULL) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

// Função auxiliar para atualizar a altura de um nó
void updateHeight(struct AVLNode *node) {
    if (node != NULL) {
        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);
        node->height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
    }
}

// Função auxiliar para realizar uma rotação simples à direita
struct AVLNode *rotateRight(struct AVLNode *y) {
    struct AVLNode *x = y->left;
    struct AVLNode *T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

// Função auxiliar para realizar uma rotação simples à esquerda
struct AVLNode *rotateLeft(struct AVLNode *x) {
    struct AVLNode *y = x->right;
    struct AVLNode *T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

// Função para criar um novo nó
struct AVLNode *createNode(char *word) {
    struct AVLNode *newNode = (struct AVLNode *)malloc(sizeof(struct AVLNode));
    newNode->word = strdup(word);
    newNode->count = 1;
    newNode->left = newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

// Função para inserir uma palavra na árvore AVL
struct AVLNode *insert(struct AVLNode *root, char *word) {
    if (root == NULL) {
        return createNode(word);
    }

    int compareResult = strcmp(word, root->word);

    // Inserção semelhante à de uma BST
    if (compareResult < 0) {
        root->left = insert(root->left, word);
    } else if (compareResult > 0) {
        root->right = insert(root->right, word);
    } else {
        // Palavra já existe, incrementa o contador
        root->count++;
        return root;
    }

    // Atualiza a altura do nó atual
    updateHeight(root);

    // Calcula o fator de balanceamento
    int balance = getBalance(root);

    // Casos de desbalanceamento

    // Rotação à direita (simples ou dupla)
    if (balance > 1 && strcmp(word, root->left->word) < 0) {
        return rotateRight(root);
    }

    // Rotação à esquerda (simples ou dupla)
    if (balance < -1 && strcmp(word, root->right->word) > 0) {
        return rotateLeft(root);
    }

    // Rotação à esquerda-direita
    if (balance > 1 && strcmp(word, root->left->word) > 0) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    // Rotação à direita-esquerda
    if (balance < -1 && strcmp(word, root->right->word) < 0) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

// Função para imprimir a árvore em-ordem
void inOrderTraversal(struct AVLNode *root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%s: %d\n", root->word, root->count);
        inOrderTraversal(root->right);
    }
}

// Função para liberar a memória alocada para a árvore AVL
void freeTree(struct AVLNode *root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root->word);
        free(root);
    }
}

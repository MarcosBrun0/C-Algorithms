//
// Created by Marcos Bruno Campos on 27/11/23.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definição de um nó da árvore
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Função para criar um novo nó
struct Node *createNode(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Função para inserir um elemento na ABB
struct Node *insert(struct Node *root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

// Percurso em-ordem (inorder)
void inOrderTraversal(struct Node *root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// Percurso pré-ordem (preorder)
void preOrderTraversal(struct Node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

// Percurso pós-ordem (postorder)
void postOrderTraversal(struct Node *root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Libera a memória alocada para a árvore
void freeTree(struct Node *root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    struct Node *root = NULL;

    // Inserir 50 números aleatórios na ABB
    for (int i = 0; i < 50; i++) {
        int randomValue = rand() % 100;  // Números aleatórios de 0 a 99
        root = insert(root, randomValue);
    }

    // Percursos
    printf("In-Order (Em-Ordem): ");
    inOrderTraversal(root);
    printf("\n");

    printf("Pre-Order (Pré-Ordem): ");
    preOrderTraversal(root);
    printf("\n");

    printf("Post-Order (Pós-Ordem): ");
    postOrderTraversal(root);
    printf("\n");

    // Liberar a memória alocada para a árvore
    freeTree(root);

    return 0;
}



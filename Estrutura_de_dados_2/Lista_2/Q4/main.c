#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da Árvore Binária
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Função para criar um novo nó da Árvore Binária
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Erro ao alocar memória para o nó!\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Função para inserir um novo nó na Árvore Binária (apenas para exemplo)
struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }

    return root;
}

// Função recursiva para busca de um elemento na Árvore Binária
struct Node* searchBST(struct Node* root, int key) {
    // Se a raiz for nula ou a chave estiver na raiz
    if (root == NULL || root->data == key) {
        return root;
    }

    // Se a chave for menor que o valor na raiz, busca na subárvore esquerda
    if (key < root->data) {
        return searchBST(root->left, key);
    }

    // Se a chave for maior que o valor na raiz, busca na subárvore direita
    return searchBST(root->right, key);
}

// Função para liberar a memória da Árvore Binária (liberação pós-ordem)
void freeBinaryTree(struct Node* root) {
    if (root != NULL) {
        freeBinaryTree(root->left);
        freeBinaryTree(root->right);
        free(root);
    }
}

// Função principal
int main() {
    // Exemplo de criação de uma Árvore Binária (ABB)
    struct Node* root = NULL;
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    int key = 40;
    struct Node* result = searchBST(root, key);

    if (result != NULL) {
        printf("Elemento %d encontrado na Árvore Binária!\n", key);
    } else {
        printf("Elemento %d não encontrado na Árvore Binária!\n", key);
    }

    // Libera a memória alocada para os nós da Árvore Binária
    freeBinaryTree(root);

    return 0;
}

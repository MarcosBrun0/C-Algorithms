//
// Created by Marcos Bruno Campos on 27/11/23.
//


#include <stdio.h>
#include <stdlib.h>

// Definição de um nó da árvore AVL
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
    int height;  // Altura do nó
};

// Função para obter a altura de um nó
int height(struct Node *node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}

// Função para calcular o fator de equilíbrio de um nó
int getBalance(struct Node *node) {
    if (node == NULL) {
        return 0;
    }
    return height(node->left) - height(node->right);
}

// Função para rotacionar à direita um subárvore com raiz em y
struct Node *rightRotate(struct Node *y) {
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    // Realiza a rotação
    x->right = y;
    y->left = T2;

    // Atualiza alturas
    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));
    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));

    return x;
}

// Função para rotacionar à esquerda um subárvore com raiz em x
struct Node *leftRotate(struct Node *x) {
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    // Realiza a rotação
    y->left = x;
    x->right = T2;

    // Atualiza alturas
    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));
    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));

    return y;
}

// Função para inserir um elemento na árvore AVL
struct Node *insert(struct Node *node, int value) {
    // Realiza a inserção padrão de uma ABB
    if (node == NULL) {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->left = newNode->right = NULL;
        newNode->height = 1;
        return newNode;
    }

    if (value < node->data) {
        node->left = insert(node->left, value);
    } else if (value > node->data) {
        node->right = insert(node->right, value);
    } else {
        // Duplicatas não são permitidas
        return node;
    }

    // Atualiza a altura do nó atual
    node->height = 1 + (height(node->left) > height(node->right) ? height(node->left) : height(node->right));

    // Obtém o fator de equilíbrio deste nó
    int balance = getBalance(node);

    // Casos de desequilíbrio

    // Rotação à esquerda-esquerda (LL)
    if (balance > 1 && value < node->left->data) {
        return rightRotate(node);
    }

    // Rotação à direita-direita (RR)
    if (balance < -1 && value > node->right->data) {
        return leftRotate(node);
    }

    // Rotação à esquerda-direita (LR)
    if (balance > 1 && value > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Rotação à direita-esquerda (RL)
    if (balance < -1 && value < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
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
    struct Node *avlRoot = NULL;

    // Inserir 50 números aleatórios na árvore AVL
    for (int i = 0; i < 50; i++) {
        int randomValue = rand() % 100;  // Números aleatórios de 0 a 99
        avlRoot = insert(avlRoot, randomValue);
    }

    // Percursos da árvore AVL
    printf("AVL Tree:\n");
    printf("In-Order (Em-Ordem): ");
    inOrderTraversal(avlRoot);
    printf("\n");

    printf("Pre-Order (Pré-Ordem): ");
    preOrderTraversal(avlRoot);
    printf("\n");

    printf("Post-Order (Pós-Ordem): ");
    postOrderTraversal(avlRoot);
    printf("\n\n");

    // Liberar a memória alocada para a árvore AVL
    freeTree(avlRoot);

    return 0;
}

//
// Created by Marcos Bruno Campos on 24/11/23.
//

//
// Created by Marcos Bruno Campos on 24/11/23.
//


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int TAMANHO = 10000;
// Definição de um nó da árvore AVL
struct Node {
    int key;
    struct Node *left, *right;
    int height;
};

// Função para calcular a altura de um nó
int getHeight(struct Node* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

// Função para calcular o fator de balanceamento de um nó
int getBalanceFactor(struct Node* node) {
    if (node == NULL)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

// Função para criar um novo nó da árvore AVL
struct Node* newNode(int key) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = node->right = NULL;
    node->height = 1;  // Novo nó tem altura 1
    return node;
}

// Função para rotacionar uma subárvore para a direita (rotação simples)
struct Node* rotateRight(struct Node* y) {
    struct Node* x = y->left;
    struct Node* T2 = x->right;

    // Realiza a rotação
    x->right = y;
    y->left = T2;

    // Atualiza alturas
    y->height = 1 + (getHeight(y->left) > getHeight(y->right) ? getHeight(y->left) : getHeight(y->right));
    x->height = 1 + (getHeight(x->left) > getHeight(x->right) ? getHeight(x->left) : getHeight(x->right));

    // Retorna a nova raiz
    return x;
}

// Função para rotacionar uma subárvore para a esquerda (rotação simples)
struct Node* rotateLeft(struct Node* x) {
    struct Node* y = x->right;
    struct Node* T2 = y->left;

    // Realiza a rotação
    y->left = x;
    x->right = T2;

    // Atualiza alturas
    x->height = 1 + (getHeight(x->left) > getHeight(x->right) ? getHeight(x->left) : getHeight(x->right));
    y->height = 1 + (getHeight(y->left) > getHeight(y->right) ? getHeight(y->left) : getHeight(y->right));

    // Retorna a nova raiz
    return y;
}

// Função para inserir um novo nó na árvore AVL
struct Node* insert(struct Node* root, int key) {
    // Passo 1: Realiza a inserção normal de uma árvore binária de busca
    if (root == NULL)
        return newNode(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    else // Ignora chaves duplicadas
        return root;

    // Passo 2: Atualiza a altura do nó atual
    root->height = 1 + (getHeight(root->left) > getHeight(root->right) ? getHeight(root->left) : getHeight(root->right));

    // Passo 3: Obtém o fator de balanceamento do nó e verifica se ele ficou desequilibrado
    int balance = getBalanceFactor(root);

    // Casos de desequilíbrio:

    // Caso Esquerda-Esquerda (LL)
    if (balance > 1 && key < root->left->key)
        return rotateRight(root);

    // Caso Direita-Direita (RR)
    if (balance < -1 && key > root->right->key)
        return rotateLeft(root);

    // Caso Esquerda-Direita (LR)
    if (balance > 1 && key > root->left->key) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    // Caso Direita-Esquerda (RL)
    if (balance < -1 && key < root->right->key) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    // Retorna o ponteiro do nó (inalterado)
    return root;
}

// Função para percorrer a árvore em ordem (in-order traversal)
void inOrderTraversal(struct Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->key);
        inOrderTraversal(root->right);
    }
}

// Função para liberar a memória alocada para a árvore
void freeTree(struct Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Função principal
int main() {
    // Semente para geração de números aleatórios
    srand(time(NULL));

    struct Node* root = NULL;

    // Preenche a árvore AVL com números aleatórios
    for (int i = 0; i < TAMANHO; i++) {
        int randomKey = rand() % 10000;
        root = insert(root, randomKey);
    }

    // Imprime a árvore em ordem
    printf("Árvore AVL em ordem: ");
    inOrderTraversal(root);
    printf("\n");

    // Calcula e imprime a altura da árvore AVL
    int treeHeight = getHeight(root);
    printf("Altura da árvore AVL: %d\n", treeHeight);

    // Libera a memória alocada para a árvore
    freeTree(root);

    return 0;
}
//
// Created by Marcos Bruno Campos on 24/11/23.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int TAMANHO = 10000;
// Definição de um nó da árvore
struct Node {
    int key;
    struct Node *left, *right;
};

// Função para criar um novo nó da árvore
struct Node* newNode(int key) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}

// Função para inserir um novo nó na árvore
struct Node* insert(struct Node* root, int key) {
    // Se a árvore estiver vazia, retorna um novo nó
    if (root == NULL) return newNode(key);

    // Caso contrário, insere recursivamente na subárvore correta
    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);

    // Retorna o ponteiro do nó (inalterado)
    return root;
}

// Função para calcular a altura da árvore
int height(struct Node* root) {
    if (root == NULL)
        return 0;
    else {
        // Recursivamente calcula a altura das subárvores esquerda e direita
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        // Retorna a altura máxima entre as subárvores mais a altura da raiz
        return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
    }
}

// Função para percorrer a árvore em ordem (in-order traversal)
void inOrderTraversal(struct Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->key);
        inOrderTraversal(root->right);
    }
}

// Função principal
int main() {
    // Semente para geração de números aleatórios
    srand(time(NULL));

    struct Node* root = NULL;

    // Preenche a árvore com números aleatórios
    for (int i = 0; i < TAMANHO; i++) {
        int randomKey = rand() % 10000;
        root = insert(root, randomKey);
    }

    // Imprime a árvore em ordem
    printf("Árvore em ordem: ");
    inOrderTraversal(root);
    printf("\n");

    // Calcula e imprime a altura da árvore
    int treeHeight = height(root);
    printf("Altura da árvore: %d\n", treeHeight);

    // Libera a memória alocada para a árvore (pode ser feito após a utilização da árvore)
    // Implementação da função de liberação de memória não incluída aqui para simplicidade.

    return 0;
}

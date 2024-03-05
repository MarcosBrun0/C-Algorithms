// avl_tree.h

#ifndef WORDCOUNT_H
#define WORDCOUNT_H

// Estrutura para um nó da árvore AVL
struct AVLNode {
    char *word;
    int count;
    struct AVLNode *left;
    struct AVLNode *right;
    int height;
};

// Função para criar um novo nó
struct AVLNode *createNode(char *word);

// Função para inserir uma palavra na árvore AVL
struct AVLNode *insert(struct AVLNode *root, char *word);

// Função para imprimir a árvore em-ordem
void inOrderTraversal(struct AVLNode *root);

// Função para liberar a memória alocada para a árvore AVL
void freeTree(struct AVLNode *root);

#endif  // AVL_TREE_H

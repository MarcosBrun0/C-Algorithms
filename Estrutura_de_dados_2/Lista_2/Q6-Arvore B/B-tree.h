// btree.h

#ifndef BTREE_H
#define BTREE_H

// Estrutura de um nó da B-tree


// Função para criar um novo nó
struct BTreeNode *createNode(int leaf);

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

#endif  // BTREE_H

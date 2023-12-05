#ifndef AVL_H
#define AVL_H

typedef struct AVLNode {
    char *word;
    int count;
    struct AVLNode *left;
    struct AVLNode *right;
    int height;
} AVLNode;

typedef AVLNode *AVLTree;

AVLTree createNode(char *word);
AVLTree insert(AVLTree node, char *word);
void inOrder(AVLTree root);
void freeTree(AVLTree root);

#endif

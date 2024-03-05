#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "AVLT.h"

int isAlpha(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(AVLNode *node) {
    return (node == NULL) ? -1 : node->height;
}

int getBalance(AVLNode *node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

AVLNode *createNode(char *word) {
    AVLNode *node = (AVLNode *)malloc(sizeof(AVLNode));

    char *lowerWord = (char *)malloc(strlen(word) + 1);
    int j = 0;

    for (int i = 0; word[i] != '\0'; i++) {
        if (isAlpha(word[i])) {
            lowerWord[j++] = tolower(word[i]);
        }
    }
    lowerWord[j] = '\0';

    node->word = lowerWord;
    node->count = 1;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;

    return node;
}

AVLNode *rightRotate(AVLNode *y) {
    AVLNode *x = y->left;
    AVLNode *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

AVLNode *leftRotate(AVLNode *x) {
    AVLNode *y = x->right;
    AVLNode *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

AVLNode *insert(AVLNode *node, char *word) {
    if (node == NULL)
        return createNode(word);

    char *lowerWord = (char *)malloc(strlen(word) + 1);
    int j = 0;

    for (int i = 0; word[i] != '\0'; i++) {
        if (isAlpha(word[i])) {
            lowerWord[j++] = tolower(word[i]);
        }
    }
    lowerWord[j] = '\0';

    if (strcmp(lowerWord, node->word) < 0)
        node->left = insert(node->left, lowerWord);
    else if (strcmp(lowerWord, node->word) > 0)
        node->right = insert(node->right, lowerWord);
    else {
        node->count++;
        free(lowerWord);
        return node;
    }

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && strcmp(lowerWord, node->left->word) < 0)
        return rightRotate(node);

    if (balance < -1 && strcmp(lowerWord, node->right->word) > 0)
        return leftRotate(node);

    if (balance > 1 && strcmp(lowerWord, node->left->word) > 0) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && strcmp(lowerWord, node->right->word) < 0) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void inOrder(AVLNode *root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%s (%d)\n", root->word, root->count);
        inOrder(root->right);
    }
}

void freeTree(AVLNode *root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root->word);
        free(root);
    }
}

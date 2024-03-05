// main.c

#include <stdio.h>
#include <stdlib.h>
#include "WordCount.h"

#define MAX_WORD_LENGTH 100

int main() {
    struct AVLNode *root = NULL;
    char word[MAX_WORD_LENGTH];

    // Abre o arquivo para leitura
    FILE *file = fopen("test.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo.\n");
        return 1;
    }

    // Lê palavras do arquivo
    while (fscanf(file, "%99s", word) != EOF) {
        root = insert(root, word);
    }

    // Fecha o arquivo
    fclose(file);

    // Imprime a árvore em-ordem
    printf("\nPalavras e contagens (em-ordem):\n");
    inOrderTraversal(root);

    // Libera a memória alocada para a árvore
    freeTree(root);

    return 0;
}

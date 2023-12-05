#include <stdio.h>
#include "AVLT.h"

int main() {
    FILE *file = fopen("teste.txt", "r");
    if (file == NULL) {
        printf("Não foi possível abrir o arquivo.\n");
        return 1;
    }

    AVLNode *root = NULL;
    char word[100];

    while (fscanf(file, "%s", word) == 1) {
        root = insert(root, word);
    }

    fclose(file);

    printf("Contagem de palavras:\n");
    inOrder(root);

    freeTree(root);

    return 0;
}

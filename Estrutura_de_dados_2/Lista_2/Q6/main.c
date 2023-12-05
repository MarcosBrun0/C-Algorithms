#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ORDER 7
#define MAX_KEYS (ORDER - 1)
#define MIN_KEYS ((ORDER - 1) / 2)

// Estrutura de um nó da B-tree
struct BTreeNode {
    int num_keys;
    int keys[MAX_KEYS];
    struct BTreeNode* children[ORDER];
    bool leaf;
};

// Estrutura para a B-tree
struct BTree {
    struct BTreeNode* root;
};

// Função para criar um novo nó da B-tree
struct BTreeNode* createNode(bool leaf) {
    struct BTreeNode* newNode = (struct BTreeNode*)malloc(sizeof(struct BTreeNode));
    if (newNode == NULL) {
        printf("Erro ao alocar memória para o nó!\n");
        exit(EXIT_FAILURE);
    }

    newNode->num_keys = 0;
    newNode->leaf = leaf;

    for (int i = 0; i < ORDER; ++i) {
        newNode->children[i] = NULL;
    }

    return newNode;
}

// Função para inicializar uma B-tree
struct BTree* initializeTree() {
    struct BTree* newTree = (struct BTree*)malloc(sizeof(struct BTree));
    if (newTree == NULL) {
        printf("Erro ao alocar memória para a árvore!\n");
        exit(EXIT_FAILURE);
    }
    newTree->root = createNode(true);
    return newTree;
}

// Função para inserir um valor na B-tree
void insert(struct BTree* tree, int key) {
    // Implementação da inserção
}

// Função para remover um valor da B-tree
void removeKey(struct BTree* tree, int key) {
    // Implementação da remoção
}

// Função para procurar um valor na B-tree
bool search(struct BTree* tree, int key) {
    // Implementação da busca
    return false;
}

// Função para imprimir a B-tree
void printTree(struct BTree* tree) {
    // Implementação da impressão
}

// Função principal (menu)
int main() {
    struct BTree* tree = initializeTree();

    // Geração de 100 números aleatórios e inserção na árvore
    // ...

    int choice, key;
    do {
        printf("\nMenu:\n");
        printf("1. Inserir um valor\n");
        printf("2. Remover um valor\n");
        printf("3. Procurar um valor\n");
        printf("4. Imprimir a árvore\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &key);
                insert(tree, key);
                break;
            case 2:
                printf("Digite o valor a ser removido: ");
                scanf("%d", &key);
                removeKey(tree, key);
                break;
            case 3:
                printf("Digite o valor a ser procurado: ");
                scanf("%d", &key);
                if (search(tree, key)) {
                    printf("Valor encontrado na árvore.\n");
                } else {
                    printf("Valor não encontrado na árvore.\n");
                }
                break;
            case 4:
                printf("Árvore B:\n");
                printTree(tree);
                break;
            case 5:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (choice != 5);

    // Liberar memória alocada para a árvore (não implementado no exemplo)

    return 0;
}

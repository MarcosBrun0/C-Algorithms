#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da Árvore AVL
struct Node {
    int data;
    int balance_factor;
    struct Node* left;
    struct Node* right;
};

// Estrutura para armazenar um nó e seu nível na Árvore AVL
struct QueueNode {
    struct Node* node;
    int level;
};

// Estrutura da fila para percurso em nível
struct Queue {
    int front, rear;
    int capacity;
    struct QueueNode* array;
};

// Função para criar um novo nó da Árvore AVL
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Erro ao alocar memória para o nó!\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->balance_factor = 0;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Função para criar uma fila
struct Queue* createQueue(int capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    if (queue == NULL) {
        printf("Erro ao alocar memória para a fila!\n");
        exit(EXIT_FAILURE);
    }
    queue->capacity = capacity;
    queue->front = queue->rear = -1;
    queue->array = (struct QueueNode*)malloc(queue->capacity * sizeof(struct QueueNode));
    if (queue->array == NULL) {
        printf("Erro ao alocar memória para os nós da fila!\n");
        exit(EXIT_FAILURE);
    }
    return queue;
}

// Verifica se a fila está vazia
int isEmpty(struct Queue* queue) {
    return queue->front == -1;
}

// Verifica se a fila está cheia
int isFull(struct Queue* queue) {
    return (queue->rear + 1) % queue->capacity == queue->front;
}

// Adiciona um nó à fila
void enqueue(struct Queue* queue, struct Node* node, int level) {
    if (isFull(queue)) {
        printf("A fila está cheia!\n");
        exit(EXIT_FAILURE);
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear].node = node;
    queue->array[queue->rear].level = level;
    if (queue->front == -1) {
        queue->front = queue->rear;
    }
}

// Remove um nó da fila
struct QueueNode dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("A fila está vazia!\n");
        exit(EXIT_FAILURE);
    }
    struct QueueNode item = queue->array[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % queue->capacity;
    }
    return item;
}

// Função para imprimir a Árvore AVL de forma hierárquica
void printAVL(struct Node* root) {
    if (root == NULL) {
        printf("Árvore AVL vazia!\n");
        return;
    }

    struct Queue* queue = createQueue(100); // Capacidade da fila
    int current_level = 0;
    enqueue(queue, root, 0);

    printf("Nível\tValor\tFator de Balanceamento\n");

    while (!isEmpty(queue)) {
        struct QueueNode qNode = dequeue(queue);
        struct Node* node = qNode.node;
        int level = qNode.level;

        if (level > current_level) {
            printf("\n");
            current_level = level;
        }

        printf("%d\t%d\t%d\n", level, node->data, node->balance_factor);

        if (node->left != NULL) {
            enqueue(queue, node->left, level + 1);
        }
        if (node->right != NULL) {
            enqueue(queue, node->right, level + 1);
        }
    }

    free(queue->array);
    free(queue);
}

// Função principal
int main() {
    // Exemplo de criação de uma Árvore AVL
    struct Node* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(15);
    root->left->left = createNode(2);
    root->left->right = createNode(7);
    root->right->left = createNode(12);
    root->right->right = createNode(20);

    // Imprime a Árvore AVL de forma hierárquica
    printAVL(root);

    // Libera a memória alocada para os nós da Árvore AVL
    // (não incluído neste exemplo para simplificação)
    
    return 0;
}

// Bibliotecas necessárias
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para reorganizar o heap subindo o elemento
void reheapUP(int *heap, int newNode) {
    int parent;
    int hold;

    if (newNode) {
        parent = (newNode - 1) / 2;
        if (heap[newNode] > heap[parent]) {
            // Troca o novo elemento com seu pai e chama reheapUP recursivamente
            hold = heap[parent];
            heap[parent] = heap[newNode];
            heap[newNode] = hold;
            reheapUP(heap, parent);
        }
    }
    return;
}

// Função para reorganizar o heap descendo o elemento
void reheapDown(int *heap, int root, int last) {
    int hold;
    int leftkey;
    int rightkey;
    int largeChildkey;
    int largeChild_index;

    if ((root * 2 + 1) <= last) {
        leftkey = heap[root * 2 + 1];
        if ((root * 2 + 2) <= last)
            rightkey = heap[root * 2 + 2];
        else
            rightkey = -1;

        // Encontra o filho com maior valor
        if (leftkey > rightkey) {
            largeChildkey = leftkey;
            largeChild_index = root * 2 + 1;
        } else {
            largeChildkey = rightkey;
            largeChild_index = root * 2 + 2;
        }

        // Se o filho com maior valor for maior que o pai, troca-os e chama reheapDown recursivamente
        if (heap[root] < heap[largeChild_index]) {
            hold = heap[root];
            heap[root] = heap[largeChild_index];
            heap[largeChild_index] = hold;
            reheapDown(heap, largeChild_index, last);
        }
    }
    return;
}

// Função de ordenação usando Heap Sort
void HeapSort(int list[], int last) {
    int sorted;
    int holdData;

    // Constrói o heap
    for (int walker = 1; walker <= last; walker++)
        reheapUP(list, walker);

    // Ordena o heap
    sorted = last;
    while (sorted > 0) {
        // Troca o primeiro elemento com o último, reorganiza o heap e reduz o tamanho do heap
        holdData = list[0];
        list[0] = list[sorted];
        list[sorted] = holdData;
        sorted--;
        reheapDown(list, 0, sorted);
    }
    return;
}

int main(void) {
    int *vet;
    int n, i;

    // Obtém o tamanho do vetor do usuário
    printf("Digite o tamanho do vetor:");
    scanf("%d", &n);

    // Aloca memória para o vetor
    vet = (int *)malloc(sizeof(int) * n);
    srand(time(NULL));

    // Preenche o vetor com números aleatórios e imprime o vetor original
    for (i = 0; i < n; i++) {
        vet[i] = rand() % 100;
        printf("[%d]", vet[i]);
    }

    printf("\n_______________HEAPSORT________________\n\n");

    // Chama a função HeapSort para ordenar o vetor
    HeapSort(vet, n - 1);

    // Imprime o vetor ordenado
    for (i = 0; i < n; i++) {
        printf("[%d]", vet[i]);
    }

    // Libera a memória alocada para o vetor
    free(vet);

    return 0;
}

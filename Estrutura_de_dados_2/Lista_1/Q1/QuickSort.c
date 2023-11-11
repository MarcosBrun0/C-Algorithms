// Inclusão de bibliotecas necessárias
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para encontrar a mediana dos três elementos (esquerda, meio e direita)
void medianLeft(int sortData[], int left, int right) {
    int mid;
    int hold;

    mid = (left + right) / 2;
    if (sortData[left] > sortData[mid]) {
        hold = sortData[left];
        sortData[left] = sortData[mid];
        sortData[mid] = hold;
    }
    if (sortData[left] > sortData[right]) {
        hold = sortData[left];
        sortData[left] = sortData[mid];
        sortData[right] = hold;
    }
    if (sortData[mid] > sortData[right]) {
        hold = sortData[mid];
        sortData[mid] = sortData[right];
        sortData[right] = hold;
    }
    hold = sortData[left];
    sortData[left] = sortData[mid];
    sortData[mid] = hold;

    return;
}

// Função principal de ordenação - QuickSort
void quickSort(int SortData[], int left, int right) {
#define MIN_SIZE 16

    int sortLeft;
    int sortRight;
    int pivot;
    int hold;

    // Se o tamanho do vetor for maior que MIN_SIZE, usa QuickSort, senão usa Insertion Sort
    if ((right - left) > MIN_SIZE) {
        medianLeft(SortData, left, right);
        pivot = SortData[left];
        sortLeft = left + 1;
        sortRight = right;

        // Particionamento do vetor
        while (sortLeft <= sortRight) {
            while (SortData[sortLeft] < pivot)
            {sortLeft = sortLeft + 1;}
            while (SortData[sortRight] >= pivot)
            {sortRight = sortRight - 1;}

            // Troca elementos
            if (sortLeft <= sortRight) {
                hold = SortData[sortLeft];
                SortData[sortLeft] = SortData[sortRight];
                SortData[sortRight] = hold;
                sortLeft = sortLeft + 1;
                sortRight = sortRight - 1;
            }
        }

        // Reorganiza recursivamente as partições
        SortData[left] = SortData[sortLeft - 1];
        SortData[sortLeft - 1] = pivot;

        if (left < sortRight)
            quickSort(SortData, left, sortRight - 1);
        if (sortLeft < right)
            quickSort(SortData, sortLeft, right);
    } else {
        // Se o tamanho for menor que MIN_SIZE, usa Insertion Sort
        quickInsertion(SortData, left, right);
    }
    return;
}

// Função de ordenação por inserção
void quickInsertion(int data[], int first, int last) {
    int hold;
    int walker;
    for (int current = first + 1; current <= last; current++) {
        hold = data[current];
        walker = current - 1;

        // Move elementos maiores que o "hold" para a direita
        while (walker >= first && hold < data[walker]) {
            data[walker + 1] = data[walker];
            walker = walker - 1;
        }

        // Coloca "hold" na posição correta
        data[walker + 1] = hold;
    }
    return;
}

int main() {
    int n, i;
    int *vet;
    srand(time(NULL));

    // Obtém o tamanho do vetor do usuário
    printf("Digite o valor de N: ");
    scanf("%d", &n);

    // Aloca memória para o vetor
    vet = (int *)malloc(sizeof(int) * n);

    // Preenche o vetor com números aleatórios e imprime o vetor original
    for (i = 0; i < n; i++) {
        vet[i] = rand() % 100;
        printf("[%d] ", vet[i]);
    }
    printf("\n");

    // Ordena o vetor usando o QuickSort
    quickSort(vet, 0, n - 1);

    // Imprime o vetor ordenado
    for (i = 0; i < n; i++) {
        printf("[%d] ", vet[i]);
    }

    // Libera a memória alocada para o vetor
    free(vet);

    return 0;
}

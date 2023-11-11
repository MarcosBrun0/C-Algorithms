#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

// Função para combinar duas metades ordenadas de um vetor
void merge(int *V, int begin, int mid, int end) {
    int *temp, p1, p2, tamanho, i, j, k;
    int fim1 = 0, fim2 = 0;
    tamanho = end - begin + 1;
    p1 = begin;
    p2 = mid + 1;
    temp = (int *)malloc(tamanho * sizeof(int)); // Vetor temporário para armazenar a fusão ordenada
    if (temp != NULL) {
        for (i = 0; i < tamanho; i++) {
            if (!fim1 && !fim2) {
                // Combina duas metades ordenadas em uma única metade ordenada
                if (V[p1] < V[p2])
                    temp[i] = V[p1++];
                else
                    temp[i] = V[p2++];
                if (p1 > mid) fim1 = 1; // Se a primeira metade é completamente usada, marca fim1 como verdadeiro
                if (p2 > end) fim2 = 1; // Se a segunda metade é completamente usada, marca fim2 como verdadeiro
            } else {
                // Copia o restante dos elementos da metade que ainda possui elementos não utilizados
                if (!fim1) temp[i] = V[p1++];
                else temp[i] = V[p2++];
            }
        }
        // Copia os elementos ordenados do vetor temporário de volta para o vetor original
        for (j = 0, k = begin; j < tamanho; j++, k++)
            V[k] = temp[j];
    }
    free(temp); // Libera o vetor temporário alocado dinamicamente
}

// Função recursiva para dividir o vetor e chamar a função merge para combinar as metades ordenadas
void mergeSort(int *V, int begin, int end) {
    int mid;
    if (begin < end) {
        mid = floor((begin + end) / 2); // Calcula o meio do vetor
        mergeSort(V, begin, mid); // Ordena a primeira metade do vetor recursivamente
        mergeSort(V, mid + 1, end); // Ordena a segunda metade do vetor recursivamente
        merge(V, begin, mid, end); // Combina as duas metades ordenadas do vetor
    }
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

    printf("\n______________MERGESORT_________________\n");

    // Chama a função mergeSort para ordenar o vetor
    mergeSort(vet, 0, n - 1);

    // Imprime o vetor ordenado
    for (i = 0; i < n; i++) {
        printf("[%d]", vet[i]);
    }

    // Libera a memória alocada para o vetor
    free(vet);

    return 0;
}

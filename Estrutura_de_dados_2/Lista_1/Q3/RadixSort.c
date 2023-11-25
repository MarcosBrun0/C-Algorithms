#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para encontrar o máximo no vetor
int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Função de counting sort para ordenar os elementos baseados no dígito significativo
void countingSort(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0};

    // Contagem das ocorrências do dígito atual no vetor
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // Atualização do array de contagem para indicar as posições reais dos números no output[]
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Construção do output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copia o output array para o vetor original
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Função principal para implementar o Radix Sort
void radixSort(int arr[], int n) {
    int max = findMax(arr, n);

    // Executa o counting sort para cada dígito, começando do dígito menos significativo até o mais significativo
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
}

int main() {
    int n;

    // Obtém o tamanho do vetor do usuário
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    // Aloca memória para o vetor
    int *vetor = (int *)malloc(sizeof(int) * n);
    srand(time(NULL));

    // Preenche o vetor com números aleatórios e imprime o vetor original
    printf("Vetor original: ");
    for (int i = 0; i < n; i++) {
        vetor[i] = rand() % 10000; // Números aleatórios entre 0 e 999
        printf("%d ", vetor[i]);
    }
    printf("\n");

    // Chama a função radixSort para ordenar o vetor
    radixSort(vetor, n);

    // Imprime o vetor ordenado
    printf("Vetor ordenado: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    // Libera a memória alocada para o vetor
    free(vetor);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Função para encontrar o maior elemento no vetor
int findMax(int vet[], int n) {
    int max = vet[0];
    for (int i = 1; i < n; i++) {
        if (vet[i] > max) {
            max = vet[i];
        }
    }
    return max;
}

// Função de ordenação Radix usando o Counting Sort
void countingSort(int vet[], int n, int exp) {
    int output[n]; // Vetor de saída
    int count[10] = {0};

    // Armazena a contagem de ocorrências em count[]
    for (int i = 0; i < n; i++) {
        count[(vet[i] / exp) % 10]++;
    }

    // Altera count[i] para que ele agora contenha a posição real deste dígito no output[]
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Constrói o vetor de saída
    for (int i = n - 1; i >= 0; i--) {
        output[count[(vet[i] / exp) % 10] - 1] = vet[i];
        count[(vet[i] / exp) % 10]--;
    }

    // Copia o vetor de saída para vet[] para que vet[] agora contenha números ordenados de acordo com o dígito atual
    for (int i = 0; i < n; i++) {
        vet[i] = output[i];
    }
}

// Função principal para executar o Radix Sort
void radixSort(int vet[], int n) {
    // Encontra o número máximo para saber o número de dígitos
    int max = findMax(vet, n);

    // Faz a ordenação para cada dígito, começando pelo dígito menos significativo até o mais significativo
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(vet, n, exp);
    }
}

// Função para imprimir um vetor
void printVet(int vet[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");
}

int main() {
    int n,i;
    int *vet;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    vet = (int *)malloc(n * sizeof(int));
    srand(time(NULL));
    for(i=0;i<n;i++){
        vet[i] = rand()%100;

    }


    printf("Vetor original: ");
    printVet(vet, n);

    radixSort(vet, n);

    printf("Vetor ordenado: ");
    printVet(vet, n);

    free(vet); // Libera a memória alocada para o vetor

    return 0;
}
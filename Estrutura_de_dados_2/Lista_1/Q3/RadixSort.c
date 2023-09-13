#include <stdlib.h>
#include <stdio.h>
#include <time.h>



void radixsort(int vetor[], int tamanho) {
    int i;
    int *b;
    int maior = vetor[0];
    int exp = 1;

    b = (int *)calloc(tamanho, sizeof(int));

    for (i = 0; i < tamanho; i++) {
        if (vetor[i] > maior)
    	    maior = vetor[i];
    }

    while (maior/exp > 0) {
        int bucket[10] = { 0 };
    	for (i = 0; i < tamanho; i++)
    	    bucket[(vetor[i] / exp) % 10]++;
    	for (i = 1; i < 10; i++)
    	    bucket[i] += bucket[i - 1];
    	for (i = tamanho - 1; i >= 0; i--)
    	    b[--bucket[(vetor[i] / exp) % 10]] = vetor[i];
    	for (i = 0; i < tamanho; i++)
    	    vetor[i] = b[i];
    	exp *= 10;
    }


    free(b);
}

int main (void){
int i,n;
int *vet;

printf("Digite um valor para N: \n");
scanf("%d", &n);
srand(time(NULL));

vet = (int)malloc(sizeof(int)*n);

for(i=0;i<n;i++){

vet[i] = rand()%100;
 printf("[%d]", vet[i]);


}
printf("\n----------------------------------\n");
radixsort(vet,n);
for(i=0;i<n;i++){

 printf("[%d]", vet[i]);
}

 return 0;
}

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int main(void){
    int *vet;
    int n,i;


    printf("Digite o tamanho do vetor:");
    scanf("%d", &n);


    vet = malloc(n);
    srand(time(NULL));

    for( i = 0; i<n;i++){
        vet[i] = rand()%100;
        printf("[%d]" ,vet[i]);
    }





    return 0;
}
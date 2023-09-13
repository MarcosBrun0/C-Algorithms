





#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

void merge(int *V, int begin, int mid, int end) {
    int *temp, p1, p2 ,tamanho, i,j,k;
    int fim1 =0 , fim2 = 0;
    tamanho = end - begin + 1;
    p1 = begin;
    p2 = mid + 1;
    temp  = (int *) malloc(tamanho*sizeof(int));
    if(temp != NULL) {
        for(i=0; i<tamanho; i++){
            if(!fim1 && !fim2) {
                if(V[p1]< V[p2])
                    temp[i]=V[p1++];
                else
                    temp[i] = V[p2++];
                if(p1 > mid) fim1 = 1;
                if(p2 > end ) fim2 =1;

            }else{
                if(!fim1) temp[i] = V[p1++];
                else temp[i]= V[p2++];
            }
        }
        for(j=0, k=begin; j < tamanho; j++,k++)
            V[k]=temp[j];

    }
    free(temp);



}
void mergeSort(int *V, int begin , int fim){

    int meio;
    if(begin < fim) {
        meio = floor(begin + fim) / 2;
        mergeSort(V, begin, meio);
        mergeSort(V, meio+1, fim );
        merge(V, begin, meio, fim);
    }
}






int main(void){
    int *vet;
    int n,i;


    printf("Digite o tamanho do vetor:");
    scanf("%d", &n);


    vet = (int)malloc(sizeof(int) * n);
    srand(time(NULL));

    for( i = 0; i<n;i++){
        vet[i] = rand()%100;
        printf("[%d]" ,vet[i]);
    }

    printf("\n_______________________________\n");
    mergeSort(vet,0,n-1);

    for(i=0;i<n;i++){
        printf("[%d]", vet[i]);
    }




    return 0;
}

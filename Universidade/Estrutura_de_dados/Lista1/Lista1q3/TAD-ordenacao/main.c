#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "tadord.c"












int main(void){

    int vetord;
    int *vet, i ;
    int n = 20;

    srand(time(NULL));
 
    vet = (int*)malloc(n*sizeof(int));
    if(vet == NULL){
   	 printf("erro na alocação");
   	 exit(1);
    }
    
    srand(time(NULL));
    
    for( i= 0 ; i<n ; i++){
   	 vet[i] = rand()%100;
   	 printf("[%d] ", vet[i]);
	 
    }
    
	printf("Vetor Original\n");

	
     vetord = Bubblesort(vet);
	 printf("Bubblesort \n");
	
	 vetord = Selectionsort(vet);
	 printf("Selectionsort\n");
	
	 vetord = Inserctionsort(vet);
	printf("Inserctionsort\n");
}
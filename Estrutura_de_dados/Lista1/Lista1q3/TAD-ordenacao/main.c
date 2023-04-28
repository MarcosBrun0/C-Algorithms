#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "tadord.c"
#include <stdbool.h>


int main(void){

    int vetord;
    int option;
    int *vet, i ;
    int n = 50000;
    bool script_on = true;
    srand(time(NULL));
 
    vet = (int*)malloc(n*sizeof(int));
    if(vet == NULL){
   	 printf("erro na alocação");
   	 exit(1);
    }
    
    srand(time(NULL));
    
    for( i= 0 ; i<n ; i++){
   	 vet[i] = rand()%999;
   	 printf("[%d] ", vet[i]);
	 
    }
    
	printf("Vetor Original\n");

while (script_on)
{
    /* code */
    printf("1 Bubble; 2 Selection ; 3 Inserction.");
    scanf("%d",&option);
	switch (option)
    {
    case 1:
    vetord = Bubblesort(vet);
	 printf("Bubblesort \n");
        /* code */
        
        break;
    
    case 2:
	 vetord = Selectionsort(vet);
	 printf("Selectionsort\n");
        break;
    case 3:

	 vetord = Inserctionsort(vet);
	printf("Inserctionsort\n");
        break;
    }
   
	
	

}
}
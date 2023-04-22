#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>




int Bubblesort(int *vet[]){


    
    int n = 20;
    int i,j;
    
   
    
   	 for( i= 0 ; i<n ; i++){
   		 for( j= n-1 ; j>i ; j--){
   			 if(vet[j]<vet[j-1]){
   				 int *temp;
   				 
   				 temp = vet[j];
   				 vet[j] = vet[j-1];
   				 vet[j-1] = temp;
   				 
   			 
   				 
   				 
   			 }
   			 
   			 
   		 }
   	 }
    
   	 printf("\n");
   	 for( i= 0 ; i<100 ; i++){
   		 printf("[%d]", vet[i]);
   		 }    
   		 
    
    
    
    
    
    
    return 0;
}








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
    
    
     vetord = Bubblesort(*vet);

}
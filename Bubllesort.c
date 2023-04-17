#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
    
    
    int *vet;
    int n = 100;
    int i,j;
    
    
    vet = (int*)malloc(n*sizeof(int));
    if(vet == NULL){
   	 printf("erro na alocação");
   	 exit(1);
    }
    
    srand(time(NULL));
    
    for( i= 0 ; i<100 ; i++){
   	 vet[i] = rand()%100;
   	 printf("[%d] ", vet[i]);
   	 
   	 
    
    }
    
    
    
   	 for( i= 0 ; i<99 ; i++){
   		 for( j= 99 ; j>i ; j--){
   			 if(vet[j]<vet[j-1]){
   				 int temp;
   				 
   				 temp = vet[j];
   				 vet[j] = vet[j-1];
   				 vet[j-1] = temp;
   				 
   			 
   				 
   				 
   			 }
   			 
   			 
   		 }
   	 }
    
   	 printf("\n");
   	 for( i= 0 ; i<100 ; i++){
   		 printf("[%d] ", vet[i]);
   		 }    
   		 
    
    
    
    
    
    
    return 0;
}


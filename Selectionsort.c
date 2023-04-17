#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
    
    
    int *vet;
    int n = 20;
    int i,j;
    int min;
    
    
    vet = (int*)malloc(n*sizeof(int));
    if(vet == NULL){
   	 printf("erro na alocação");
   	 exit(1);
    }
    
    srand(time(NULL));
    
    for( i= 0 ; i<20 ; i++){
   	 vet[i] = rand()%100;
   	 printf("[%d] ", vet[i]);
   	 
   	 
    
    }
    
    for( i = 0; i <19;i ++){
   	 min = i;
   	 for(j=i+1;j<20;j++){
   		 if(vet[min]>vet[j]){
   			 min = j;
   		 }
   	 }
   	 int temp = vet[i];
   	 vet[i] = vet[min];
   	 vet[min] = temp;
    }
    
   	 printf("\n");
    
    for (i =0;i<20; i++){
   	 printf("[%d] ", vet[i]);
    }
    
    
    
    
    
    
return 0;
}



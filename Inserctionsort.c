#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
    
    
    int *vet;
    int n = 20;
    int i,j;
    int key;
    
    
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
    
    for( i = 0; i <20;i ++){
   	 key = vet[i];
   	 j = i-1;
   	 while(j>=0 && key<vet[j]){
   		 
   	 vet[j+1]= vet[j];
   	 j--;
   	 }
   	 vet[j+1] = key;
   	 
    }
    printf("\n");
    for(i = 0; i<20;i++){
   	 printf("[%d] ", vet[i]);
    }
    
return 0;
}

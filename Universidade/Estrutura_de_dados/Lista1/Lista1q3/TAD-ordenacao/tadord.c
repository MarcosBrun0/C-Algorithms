#include <math.h>
#include <stdio.h>
#include <stdlib.h>


const  int n = 50000;


int Bubblesort(int *vet){


    
   
    int i,j;
    
   
    
   	 for( i= 0 ; i<n ; i++){
   		 for( j= n-1 ; j>i ; j--){
   			 if(vet[j]<vet[j-1]){
   				 int temp;
   				 
   				 temp = vet[j];
   				 vet[j] = vet[j-1];
   				 vet[j-1] = temp;
   				 
   			 
   				 
   				 
   			 }
   			 
   			 
   		 }
   	 }
    
   	 printf("\n");
   	 for( i= 0 ; i<n ; i++){
   		 printf("[%d] ", vet[i]);
   		 }    
   		 
    
    
    
    
    
    
    return 0;
}

//SELECTION SORT

int Selectionsort(int *vet){
int min = 0, i,j;

 for( i = 0; i <n-1;i ++){
   	 min = i;
   	 for(j=i+1;j<n;j++){
   		 if(vet[min]>vet[j]){
   			 min = j;
   		 }
   	 }
   	 int temp = vet[i];
   	 vet[i] = vet[min];
   	 vet[min] = temp;
    }
    
   	 printf("\n");
    
    for (i =0;i<n; i++){
   	 printf("[%d] ", vet[i]);
    }
    
    
    
    
    
    
return 0;



}

// INSERCTION SORT
int Inserctionsort(int *vet){

    int key,i,j;


 for( i = 0; i <n;i ++){
   	 key = vet[i];
   	 j = i-1;
   	 while(j>=0 && key<vet[j]){
   		 
   	 vet[j+1]= vet[j];
   	 j--;
   	 }
   	 vet[j+1] = key;
   	 
    }
    printf("\n");
    for(i = 0; i<n;i++){
   	 printf("[%d] ", vet[i]);
    }
    
return 0;





}
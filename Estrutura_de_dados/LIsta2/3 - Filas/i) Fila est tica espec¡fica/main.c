#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "FilaEstaticaEspecifica.h"

int main() {
    Fila *f;													//ponteiro do tipo fila
    f = cria_Fila();											//cria fila	atribuida ao ponteiro
	int v[7] = {1, 8, 3, 1, 5, 7, 8};							//vetor com 7 elementos
	int i;		
	
	printf("Vetor: ");
	for (i=0; i<=6; i++) {										//mostra vetor
		printf("%d ", v[i]);
	}
	
	printf("\n");
	
	for (i=0; i<=6; i++) {										//insere cada elemento na fila
		enfilera_Fila(f, v[i]);
	}
	
	
	printf("\n");
	
	printf("\nA fila tem %d elementos\n", tamanho_Fila(f));	   //mostra quantidade de elementos
	
	
	for(i=0; !Fila_vazia(f); i++) {						       //se fila diferente de vazia
		v[i]= desenfilera_Fila(f);							   //remove elementos da fila e adiciona no vetor
		printf(" e adicionado ao vetor ");
	}
 
 	printf("\n");
 	
	printf("\nVetor: ");								    	//mostra vetor com saida dos elementos da fila
	for (i=0; i<=6; i++) {
		printf("%d ", v[i]);
	}
	
	return 0;
}

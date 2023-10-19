#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "PilhaEstaticaEspecifica.h" 

int main () {
	int i;
	Pilha *p;
	p = cria_Pilha();
	
	Pilha_vazia(p);
	
	int v[5] = {1, 2, 3, 4, 5};
	
	printf("Vetor: ");
	for (i=0; i<=4; i++) {
		printf("%d ", v[i]);
	}
	
	printf("\n\n");
	
	for (i=0; i<=4; i++) {
		insere_Pilha(p, v[i]);
	}
	
	printf("\nA pilha possui %d elementos\n", tamanho_Pilha(p));
	
	Pilha_vazia(p);
	
	for(i=0; !Pilha_vazia(p); i++) {
		v[i]= remove_Pilha(p);
		printf(" e adicionado ao vetor ");
	}
	
	printf("\n\nVetor inverso: ");
	for (i=0; i<=4; i++) {
		printf("%d ", v[i]);
	}	

	return 0;
}


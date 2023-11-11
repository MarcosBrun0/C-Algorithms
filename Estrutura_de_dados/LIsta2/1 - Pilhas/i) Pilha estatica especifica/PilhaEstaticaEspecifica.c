#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "PilhaEstaticaEspecifica.h"

struct pilha {
	int contador;
	int itens[TAMANHO];
};

Pilha* cria_Pilha() {     					//Cria a pilha
	Pilha *p;
	p = (Pilha*)malloc(sizeof(Pilha));
	
	if (p != NULL) {
		p->contador = 0;
	}
	return p;
}

int Pilha_vazia(Pilha *p) {					//Verifica se a pilha está vazia
	if (p == NULL) {
		return -1;
	}
	return (p->contador == 0);
}

int Pilha_cheia(Pilha *p) { 	   			//Verifica se a pilha está cheia
	if(p == NULL) {
		return -1;
	}
	return (p->contador == TAMANHO);
}

int insere_Pilha(Pilha *p, int n) {			//insere elemento na pilha
	if (p == NULL) {
		printf("\nPilha não existe!"); 		//pilha não existe
		return 0;
	}
	if (p->contador == TAMANHO){  			//pilha cheia
		printf("\nPilha cheia!");
		return 0;
	}
	p->itens[p->contador] = n;
	(p->contador)++;
	printf("%d foi adicionado a pilha\n", n);
	return 1;
}

int remove_Pilha(Pilha *p) {				//remove elemento do topo da pilha
	if ((p == NULL)||(p->contador == 0)){
		return -1;
	}
	p->contador--;
	
	printf("\n%d foi removido da pilha", p->itens[p->contador]);
	return p->itens[p->contador];
}

int topo_Pilha(Pilha *p) {					//mostra elemento do topo da pilha
	if ((p == NULL) || (p->contador == 0)){
		return -1;
	} 
	return (p->itens[p->contador]);
}

int tamanho_Pilha(Pilha *p) {    //Número de elementos da pilha
	if (p == NULL) {
		return -1;
	}
	return (p->contador);
}

int destroi_Pilha(Pilha *p) {		 //Tira todos os elementos da pilha
	free(p);
}


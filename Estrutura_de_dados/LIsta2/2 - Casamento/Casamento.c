#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Casamento.h"

 struct node{
    void* dataPtr;					//ponteiro que aramazena dados
    struct node* link;				//ponteiro que aponta pro próximo nó
};

struct pilha{
    int contador;					//contador
    Pilha_node* top;				//ponteiro do nó mais recente
};

Pilha* cria_Pilha() {     			//Cria a pilha
	Pilha *p;
	p = (Pilha*)malloc(sizeof(Pilha));
	
	if (p != NULL) {
		p->contador = 0;
		p->top = NULL;
	}
	return p;
}

int Pilha_vazia(Pilha* p) {			//Verifica se a pilha está vazia
	return (p->contador == 0);
}

int Pilha_cheia(Pilha* p) {
	Pilha_node *aux;
	
	aux = (Pilha_node*)malloc(sizeof(*(p->top)));
	
	if(aux != NULL) {					//se alocação for bem sucedida
		free(aux);						// tem espaço na pilha, e então limpa
		return 0;						// a memórica alocada e retorna que a pilha não ta cheia
	}
	return 1;							//pilha cheia
}

int insere_Pilha(Pilha* p, void* dataInPtr) {		//insere elemento na pilha
	Pilha_node* newPtr;								// novo nó
		
	newPtr = (Pilha_node*)malloc(sizeof(Pilha_node));	// alocação de memória novo nó
	
	if(!newPtr) {
		return 0;
	}
	
	newPtr->dataPtr = dataInPtr;		//dataPtr do novo nó atribuido ao novo endereço alocado
	newPtr->link = p->top;				//ponteiro link do novo nó aponta pro antigo topo da pilha 
	p->top = newPtr;					//ponteiro topo da pilha aponta pro novo nó
	
	(p->contador)++;
	return 1;
}

void* remove_Pilha(Pilha* p) {				//remove elemento do topo da pilha
	void* dataOutPtr;						
	Pilha_node* aux;						
	
	if (p->contador == 0){
		dataOutPtr = NULL;
	}
	
	aux = p->top;							//armazena endereço que está no nó do top atualmente
	dataOutPtr = p->top->dataPtr;			//recebe o conteúdo desse topo a ser removido
	p->top = p->top->link;					//top aponta pro link do nó do elemento abaixo 
	
	free(aux);								//libera endereço do top atual 
	(p->contador)--;						//decrementa contador
	
	return dataOutPtr;						//retorna elemento removido
}

void* topo_Pilha(Pilha* p) {				//mostra elemento do topo da pilha
	if (p->contador == 0){
		return NULL;
	} 
	return (p->top->dataPtr);				//aponta pro conteúdo do topo da pilha sem remove-lo
}

int tamanho_Pilha(Pilha* p) {   			//Número de elementos da pilha
	return (p->contador);
}

Pilha* destroi_Pilha(Pilha* p) {			 //Tira todos os elementos da pilha
	Pilha_node *aux;
	
	if(p != NULL) {
		while (p->top != NULL){		
			free(p->top->dataPtr);
			aux = p->top;
			p->top = p->top->link;
			free(aux);
		}
	}
	free(p);
	return NULL;
}

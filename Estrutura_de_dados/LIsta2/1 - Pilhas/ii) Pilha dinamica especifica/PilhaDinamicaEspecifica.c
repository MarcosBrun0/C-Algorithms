#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "PilhaDinamicaEspecifica.h"

struct node {						
	int* dataPtr;					//ponteiro que aramazena dados
	struct node* link;				//ponteiro que aponta pro pr�ximo n�
};

struct pilha {
	int contador;					//contador
	Pilha_node* top;				//ponteiro do n� mais recente
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

int Pilha_vazia(Pilha* p) {			//Verifica se a pilha est� vazia
	return p->contador == 0;		
}

int Pilha_cheia(Pilha* p) {
	Pilha_node *aux;
	
	aux = (Pilha_node*)malloc(sizeof(*(p->top)));
	
	if(aux != NULL) {					//se aloca��o for bem sucedida
		free(aux);						// tem espa�o na pilha, e ent�o limpa
		return 0;						// a mem�rica alocada e retorna que a pilha n�o ta cheia
	}
	return 1;							//pilha cheia
}

int insere_Pilha(Pilha* p, int* dataInPtr) {		//insere elemento na pilha
	Pilha_node* newPtr;								// novo n�
	
	newPtr = (Pilha_node*)malloc(sizeof(Pilha_node)); // aloca��o de mem�ria novo n�
	
	if(!newPtr) {
		return 0;
	}
	
	newPtr->dataPtr = dataInPtr;			//dataPtr do novo n� atribuido ao novo endere�o alocado
	newPtr->link = p->top;					//ponteiro link do novo n� aponta pro antigo topo da pilha 
	p->top = newPtr;						//ponteiro topo da pilha aponta pro novo n�
	
	(p->contador)++;
	return 1;
}

int* remove_Pilha(Pilha* p) {				//remove elemento do topo da pilha
	int* dataOutPtr;						
	Pilha_node* aux;						
	
	if (p->contador == 0){					//verifica se a pilha est� vazia
		dataOutPtr = NULL;
	}
	
	aux = p->top;							//armazena endere�o que est� no n� do top atualmente
	dataOutPtr = p->top->dataPtr;			//recebe o conte�do desse topo a ser removido
	p->top = p->top->link;					//top aponta pro link do n� do elemento abaixo 
	
	free(aux);								//libera endere�o do top atual 
	(p->contador)--;						//decrementa contador
	
	return dataOutPtr;						//retorna elemento removido
}

int* topo_Pilha(Pilha* p) {					//mostra elemento do topo da pilha
	if (p->contador == 0){
		return NULL;
	} 
	return (p->top->dataPtr);				//aponta pro conte�do do topo da pilha sem remove-lo
}

int tamanho_Pilha(Pilha* p) {   		 	//N�mero de elementos da pilha
	return (p->contador);
}

Pilha* destroi_Pilha(Pilha* p) {			//Tira todos os elementos da pilha
	Pilha_node *aux;
	
	if(p != NULL) {
		while (p->top->dataPtr){			//enquanto existir elementos(n�) na pilha
			aux = p->top;					//usa o aux pra receber endere�o do topo
			p->top = p->top->link;			//top aponta pro link do n� do elemento abaixo 
			free(aux);						//libera endere�o do topo
		}		
	}
	
	free(p);								//libera o endere�o do p (estrutura pilha)
	return NULL;		
}

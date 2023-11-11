#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "FilaDinamicaEspecifica.h"

struct node {						
    void* dataPtr;									// armazena dado
    struct node* proximo;							//aponta para próximo nó da lista
};

struct fila {
    Fila_node* primeiro;							//cria ponteiro para apontar para o primerio da fila
    Fila_node* ultimo;								//cria ponteiro para apontar para o ultimo da fila
    int contador;									//contra numeros de elementos da fila
};

Fila* cria_Fila() {									//cria fila
    Fila* f; 										//cria ponteiro do tipo fila
	f = (Fila*)malloc(sizeof(Fila)); 				//aloca memória para ponteiro

    if(f != NULL) {									//inicializa os ponteiros
        f->primeiro = NULL;
        f->ultimo = NULL;
        f->contador = 0;
    }
    return f;										//retorna a fila
}

int Fila_vazia(Fila* f) {							//verifica se a fila está vazia
    return (f->contador == 0); 						//compara se o contador é igual a 0
}

int Fila_cheia(Fila* f) {			
    Fila_node *aux;

    aux = (Fila_node*)malloc(sizeof(Fila_node));	//tenta alocar memória para um auxiliar, se conseguir fila não está cheia, senão está cheia
    if(aux) {
        free(aux); 
        return 0;
    }
    return 1; 
}

int enfilera_Fila(Fila* f, int* itemPtr) {			//enfilera elementos
    Fila_node* newPtr;								//cria ponteiro pro novo nó
    newPtr = (Fila_node*)malloc(sizeof(Fila_node)); //aloca memória para o novo nó

    if(!newPtr) {									
        return 0;
    }
    
    newPtr->dataPtr = itemPtr; 						//endereço do itemPtr é atribuido ao dataPtr do novo nó
    newPtr->proximo = NULL;							//atribui ao ponteiro do próximo como NULL
    
	if(f->contador == 0) {							//se a fila estiver vazia
    	f->primeiro = newPtr;						//novo nó é o primeiro da fila, dessa forma o newPtr é primeiro elemento
	}else {
		f->ultimo->proximo = newPtr;				//vai ser inserido no depois do ultimo o newPtr
	}
    (f->contador)++;								//incrementa contador
    f->ultimo = newPtr; 							//atualiza o ponteiro ultimo
   
    return 1;
}

int desenfilera_Fila(Fila* f, int**itemPtr) {		//tira elementos da fila
    Fila_node* excluiLoc; 							//cria ponteiro temporário para elemento a ser removido

    if(!f->contador) {								//verifica se fila está vazia
        return 0;
    }

    *itemPtr = f->primeiro->dataPtr;				//atribui ao ponteiro de ponteiro o endereço do dado do primeiro elemento da fila
    excluiLoc = f->primeiro;						//o ponteiro primeiro é passado

    if(f->contador==1) {							// se fila possui apenas um elementos
        f->ultimo = f->primeiro = NULL;				// serão atualizados para NULL
    }else {
        f->primeiro = f->primeiro->proximo; 		//se mais de um, o primeiro vai receber o próximo nó que possui o elemento depois do primeiro
    }

    (f->contador)--;								//decrementa contador
    free(excluiLoc);								//libera memória alocada para ponteiro temporário

    return 1;
}

int tamanho_Fila(Fila* f) {							//retorna numero existente no contador
    return f->contador; 
}

int primeiro_Fila(Fila* f, int** itemPtr) {			//mostra primeiro elemento da fila sem retirar
    if(!f->contador) {								//verifica se está vazia
        return 0;				
    } else {
        *itemPtr = f->primeiro->dataPtr; 			//ponteiro de ponteiro itemPtr recebe o endereço do dado do primeiro elemento
        return 1;
    }
}

int ultimo_Fila(Fila* f, int**itemPtr) {			//mostra ultimo da fila
    if(!f->contador) {								//verifica fila vazia
        return 0;
    } else{
        *itemPtr = f->ultimo->dataPtr; 				//ponteiro de ponteiro recebe o endereço do dado do ultimo elemento
        return 1;
    }
}

Fila* destroi_Fila(Fila* f) {						//libera memória alocada pra fila
    Fila_node* deletePtr; 

    if(f != NULL) {
        while(f->primeiro != NULL) {
            free(f->primeiro->dataPtr);				//libera memória alocada pro dataPtr
            deletePtr = f->primeiro; 				//recebe endereço do primeiro nó
            f->primeiro = f->primeiro->proximo; 	//atualiza o ponteiro do primeiro para o próximo
            free(deletePtr); 						//libera memória alocada para ponteiro temporário
        }
        free(f); 									//libera memória alocada pra a fila
    }
    return NULL; 
}

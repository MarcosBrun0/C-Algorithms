#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "FilaDinamicaGenerica.h"

struct node {
    void* dataPtr;									// armazena dado
    struct node* proximo;							//aponta para pr�ximo n� da lista
};

struct fila {
    Fila_node* primeiro;							//cria ponteiro para apontar para o primerio da fila
    Fila_node* ultimo;								//cria ponteiro para apontar para o ultimo da fila
    int contador;									//contra numeros de elementos da fila
};
	
Fila* cria_Fila() {									//cria fila
    Fila* f; 										//cria ponteiro do tipo fila
	f = (Fila*)malloc(sizeof(Fila)); 				//aloca mem�ria para ponteiro

    if(f != NULL) {
        f->primeiro = NULL;							//inicializa os ponteiros
        f->ultimo = NULL;
        f->contador = 0;
    }
    return f;										//retorna a fila
}

bool Fila_vazia(Fila* f) {							//verifica se a fila est� vazia
    return (f->contador == 0); 						//compara se o contador � igual a 0
}

bool Fila_cheia(Fila* f) {
    Fila_node *aux;

    aux = (Fila_node*)malloc(sizeof(Fila_node));    //tenta alocar mem�ria para um auxiliar, se conseguir fila n�o est� cheia, sen�o est� cheia
    if(aux) {
        free(aux); 
        return 0;
    }
    return 1; 
}

bool enfilera_Fila(Fila* f, void* itemPtr) {		//enfilera elementos
    Fila_node* newPtr;								//cria ponteiro pro novo n�
    newPtr = (Fila_node*)malloc(sizeof(Fila_node)); //aloca mem�ria para o novo n�

    if(!newPtr) {
        return false;
    }
    
    newPtr->dataPtr = itemPtr; 						//endere�o do itemPtr � atribuido ao dataPtr do novo n�
    newPtr->proximo = NULL;							//atribui ao ponteiro do pr�ximo como NULL
    
	if(f->contador == 0) {							//se a fila estiver vazia
    	f->primeiro = newPtr;						//novo n� � o primeiro da fila, dessa forma o newPtr � primeiro elemento 	
	}else {
		f->ultimo->proximo = newPtr;				//vai ser inserido no depois do ultimo o newPtr
	}
    (f->contador)++;								//incrementa contador
    f->ultimo = newPtr; 							//atualiza o ponteiro ultimo
   
    return true;
}

bool desenfilera_Fila(Fila* f, void**itemPtr) {		//tira elementos da fila
    Fila_node* excluiLoc; 							//cria ponteiro tempor�rio para elemento a ser removido

    if(!f->contador) {								//verifica se fila est� vazia
        return false;
    }

    *itemPtr = f->primeiro->dataPtr;				//atribui ao ponteiro de ponteiro o endere�o do dado do primeiro elemento da fila
    excluiLoc = f->primeiro;						//o ponteiro primeiro � passado

     if(f->contador==1) {							// se fila possui apenas um elementos
        f->ultimo = f->primeiro = NULL;				// ser�o atualizados para NULL
    }else {
        f->primeiro = f->primeiro->proximo; 		//se mais de um, o primeiro vai receber o pr�ximo n� que possui o elemento depois do primeiro
    }

    (f->contador)--;								//decrementa contador
    free(excluiLoc);								//libera mem�ria alocada para ponteiro tempor�rio


    return true;
}

int tamanho_Fila(Fila* f) {
    return f->contador; 							//retorna numero existente no contador
}

bool primeiro_Fila(Fila* f, void** itemPtr) {		//mostra primeiro elemento da fila sem retirar
    if(!f->contador) {								//verifica se est� vazia
        return false;
    } else {
        *itemPtr = f->primeiro->dataPtr; 			//ponteiro de ponteiro itemPtr recebe o endere�o do dado do primeiro elemento
        return true;
    }
}

bool ultimo_Fila(Fila* f, void**itemPtr) {			//mostra ultimo da fila
    if(!f->contador) {								//verifica fila vazia
        return false;
    } else{
        *itemPtr = f->ultimo->dataPtr; 				//ponteiro de ponteiro recebe o endere�o do dado do ultimo elemento
        return true;
    }
}

Fila* destroi_Fila(Fila* f) {						//libera mem�ria alocada pra fila
    Fila_node* deletePtr; 

    if(f != NULL) {
        while(f->primeiro != NULL) {
            free(f->primeiro->dataPtr);				//libera mem�ria alocada pro dataPtr
            deletePtr = f->primeiro; 				//recebe endere�o do primeiro n�
            f->primeiro = f->primeiro->proximo; 	//atualiza o ponteiro do primeiro para o pr�ximo
            free(deletePtr); 						//libera mem�ria alocada para ponteiro tempor�rio
        }
        free(f); 									//libera mem�ria alocada pra a fila
    }
    return NULL; 
}

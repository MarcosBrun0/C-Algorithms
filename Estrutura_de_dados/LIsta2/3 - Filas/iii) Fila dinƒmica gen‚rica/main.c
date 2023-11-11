#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "FilaDinamicaGenerica.h"

int main() {
    Fila *f;													// ponteiro para a fila
    float *item;												// ponteiro pro item a ser inserido
    bool done = false;											// variavel que determina o fim da entrada de elementos
    float *elem;												// ponteiro pro elemento a ser removido
    
    f = cria_Fila();											// cria fila

	printf("Digite um numero (para parar digite -1): \n");		// pede ao usuário
    while(!done) {
        item = (float*)malloc(sizeof(float));					// aloca memória para o ponteiro que vai receber o novo item
        scanf("%f", item);										// le o número e armazena no item
        if(*item != -1) {										// condição de parada
        	printf("%f entrou na fila\n", *item);				//	mostra o numero que entrou na fila
        	enfilera_Fila(f, item);								// enfilera esse elemento que entrou
        } else{
            done = true;										// para o while
        }
    }

    printf("\nA fila tem %d elementos: ", tamanho_Fila(f));		//mostra quantidade de elementos

    while(!Fila_vazia(f)) {										//verifica fila vazia
        desenfilera_Fila(f, (void**)&elem);						//remove elementos e atribui o valor ao ponteiro elem
        printf("%f ",*elem);									//mostra o elemento
    }
    return 0;
}


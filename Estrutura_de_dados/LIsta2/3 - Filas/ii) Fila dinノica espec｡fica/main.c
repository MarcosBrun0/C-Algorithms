#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "FilaDinamicaEspecifica.h"

int main() {
    Fila *f;															// ponteiro para a fila
    int *item;															// ponteiro pro item a ser inserido
    int done = 0;														// variavel que determina o fim da entrada de elementos
    int *elem;															// ponteiro pro elemento a ser removido
    
    f = cria_Fila();													// cria fila

	printf("Digite um numero inteiro (para parar digite -1): \n");		// pede ao usuário
    while(!done) {														
        item = (int*)malloc(sizeof(int));								// aloca memória para o ponteiro que vai receber o novo item
        scanf("%d", item);												// le o número e armazena no item
        if(*item != -1) {												// condição de parada
        	printf("%d entrou na fila\n", *item);						//	mostra o numero que entrou na fila
        	enfilera_Fila(f, item);										// enfilera esse elemento que entrou
        } else{	
            done = 1;													// para o while
        }
    }

    printf("\nA fila tem %d elementos: ", tamanho_Fila(f));				//mostra quantidade de elementos

    while(!Fila_vazia(f)) {												//verifica fila vazia
        desenfilera_Fila(f, &elem);										//remove elementos e atribui o valor ao ponteiro elem
        printf("%d ", *elem);											//mostra o elemento
    }
}

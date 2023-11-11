#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ListaDinamicaEspecifica.h"

int compara_valor(int* argu1, int* argu2) {									
    if (*argu1 < *argu2)													
        return -1;
    else if (*argu1 > *argu2)												
        return 1;	
    else
        return 0;
}

int main() {
    Lista* minhaLista = cria_Lista(compara_valor);							//cria lista

    int *getData;															//declara ponteiro para dados que irão sair da lista

    getData = (int*)(malloc(sizeof(int)));									//aloca memória para getData
    
    int valor1, valor2, valor3, valor4;
    
    valor1 = 15;															//define valores
    valor2 = 30;
    valor3 = 60;
    valor4 = 120;
    
    adiciona_No(minhaLista, &valor1);										//adiciona valores a lista
    adiciona_No(minhaLista, &valor2);
    adiciona_No(minhaLista, &valor3);
    adiciona_No(minhaLista, &valor4);										

    printf("\nLista ordenada: ");
	print_Lista(minhaLista);												//mostra lista

  	remove_No(minhaLista, &valor3, &getData);								//remove nó da lista
    
	printf("\nLista apos a remocao: ");										//mostra lista após a remoção
	print_Lista(minhaLista);

	return 0;
}

#include <stdio.h>
#include "SomaPolinomio.h"

int compara_numeros(void* primeiroArg, void* segundoArg) {
    int* a = (int*)primeiroArg;
    int* b = (int*)segundoArg;

    if (*a < *b) {
        return -1;
    } else if (*a > *b) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
	int data1, data2, data3, data5, data6, data7;
	int expoente1, expoente2, expoente3, expoente5, expoente6, expoente7;	//declara variaveis
    
	Lista* lista1 = cria_Lista(compara_numeros);							//cria 3 listas
    Lista* lista2 = cria_Lista(compara_numeros);
    Lista* resultado = cria_Lista(compara_numeros);
    Lista* result;															//cria ponteiro result										
	
    data1 = 7;																//declara numero para variaveis
    expoente1 = 0;
    
    data2 = 6;
   	expoente2 = 3;

	data3 = 5;
	expoente3 = 4;

    data5 = 3;
    expoente5 = 1;

    data6 = 7;
    expoente6 = 2;

    data7 = 2;
    expoente7 = 3;

 	adiciona_No(lista1, &data1, &expoente1);				//adiciona nos
    adiciona_No(lista1, &data2, &expoente2);
    adiciona_No(lista1, &data3, &expoente3);
    
    printf("Primeiro polinomio: ");							//mostra polinomio
    mostra_Polinomio(lista1);

   	adiciona_No(lista2, &data5, &expoente5);
    adiciona_No(lista2, &data6, &expoente6);
    adiciona_No(lista2, &data7, &expoente7);

	printf("Segundo polinomio: ");							//mostra segundo polinomio
    mostra_Polinomio(lista2);
    
    result = soma_Polinomio(lista1, lista2, resultado);		//faz a soma dos polinomios

    printf("Soma dos polinomios: ");
    mostra_Polinomio(result);								//imprime a soma dos polinomios

    return 0;
}

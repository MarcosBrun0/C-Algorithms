#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cType.h>
#include <stdbool.h>
#include "ListaDupla.h"

int main (){
	Lista* l;
	int x;

	l = cria_lista();
	
	printf("\nPara percorrer a lista de forma crescente digite 1, se decrescente digite 0: \n");
	scanf("%d", &x);
	
	mostra_Lista(l, x);

	destroi_Lista(l);
	
	return 0;
}


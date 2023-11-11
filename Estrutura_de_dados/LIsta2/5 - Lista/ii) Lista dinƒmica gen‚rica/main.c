#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ListaDinamicaGenerica.h"

int compara_valor(void* argu1, void* argu2) {
    if (argu1 < argu2)
        return -1;
    else if (argu1 > argu2)
        return 1;
    else
        return 0;
}

int main() {
    Lista* l;
	int *getData;
	l = cria_Lista(compara_valor);

    adiciona_No(l, 4);
    adiciona_No(l, 9);
    adiciona_No(l, 2);
    adiciona_No(l, 17);
    
    recupera_No(l, 9, &getData);
    
	return 0;
}

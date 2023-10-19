#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "ClassificacaodePalavras.h"

struct node {
    void* dataPtr;
    struct node* proximo;
};

struct fila {
    char *letra;
    Fila_node* primeiro;
    Fila_node* ultimo;
    int contador;
};

Fila* cria_Fila(char *inicial) {
    Fila* f;

    f = (Fila*)malloc(sizeof(Fila)); 

    if(f) {
        f->letra = *inicial;
        f->primeiro = NULL;
        f->ultimo = NULL;
        f->contador = 0;
    }

    return f;
}

bool enfilera_Fila(Fila* f, void**itemPtr) {
    Fila_node* newPtr;
    newPtr = (Fila_node*)malloc(sizeof(Fila_node));

    if(!newPtr) {
        return false;
    }

    newPtr->dataPtr = *itemPtr; 
    newPtr->proximo = NULL;

    if(f->contador == 0)
        f->primeiro = newPtr; 
    else
        f->ultimo->proximo = newPtr; 

    (f->contador)++;
    f->ultimo = newPtr; 
    return true;
}

bool desenfilera_Fila(Fila* f, void**itemPtr) {
    Fila_node* deleteLoc; // Ponteiro temporario

    if(!f->contador) {
        return false;
    }

    *itemPtr = f->primeiro->dataPtr;
    deleteLoc = f->primeiro;

    if(f->contador==1) {
        f->ultimo = f->primeiro = NULL;
    } else {
        f->primeiro = f->primeiro->proximo; 
    }

    (f->contador)--;
    free(deleteLoc);

    return true;
}

bool primeiro_Fila(Fila* f, void** itemPtr) {
    if(!f->contador) {
        return false;
    } else {
        *itemPtr = f->primeiro->dataPtr; 
        return true;
    }
}

bool ultimo_Fila(Fila* f, void**itemPtr) {
    if(!f->contador) {
        return false;
    } else{
        *itemPtr = f->ultimo->dataPtr;
        return true;
    }
}

bool Fila_vazia(Fila* f) {
    return (f->contador == 0);
}

bool Fila_cheia(Fila* f) {
    Fila_node *aux;

    aux = (Fila_node*)malloc(sizeof(Fila_node)); 
    if(aux) {
        free(aux);
        return false;
    }
    return true;
}

int tamanho_Fila(Fila* f) {
    return f->contador; 
}

Fila* destroi_Fila(Fila* f) {
    Fila_node* deletePtr;

    if(f) {
        while(f->primeiro != NULL) {
            free(f->primeiro->dataPtr); 
            deletePtr = f->primeiro; 
            f->primeiro = f->primeiro->proximo; 
            free(deletePtr); 
        }
        free(f);
    }
    return NULL;
}

int encontrar_Indice(char *letra) {
    *letra = tolower(*letra);						//converte letras minusculo
    if(*letra >= 'a' && *letra <= 'z')      		//entre a e z
        return (*letra) - 'a';						//retorna o indice de 0 a 25 pq subtrai o valor de a do caractere
    else
        return -1;
}

void mostra_Fila(Fila *f) {
    Fila_node* now = f->primeiro;					// cria um ponteiro que aponta pro primeiro da fila

    while(now != NULL) {
        printf("%s ", now->dataPtr);				//mostra dado do nó atual
        now = now->proximo;							//atualiza o now pro proximo da fila
    }
    printf("\n");
}

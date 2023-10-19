#include <stdio.h>
#include <stdlib.h>
#include "ListaDinamicaGenerica.h"

struct node
{   void*        dataPtr;
    struct node* link;
};

struct lista
{   int  contador;
    Lista_node* pos;
    Lista_node* primeiro;
    Lista_node* ultimo;
    int (*compara) (void* argu1, void* argu2);
};

Lista* cria_Lista (int (*compara) (void* argu1, void* argu2)) {
	Lista* l;

	l = (Lista*) malloc (sizeof(Lista));
	if (l) {
	    l->primeiro = NULL;
	    l->pos = NULL;
	    l->ultimo = NULL;
	    l->contador = 0;
	    l->compara = compara;
	   } 
	return l;
}	

int adiciona_No (Lista* pList, void* dataInPtr) {
	bool encontrado;
	bool sucesso;

	Lista_node* pPre;
	Lista_node* pLoc;
	
	printf("\nAdicionado a Lista: %d", dataInPtr);
	
	encontrado = _procura (pList, &pPre, &pLoc, dataInPtr);
	if (encontrado)
	   return (+1);

	sucesso = insere_Lista (pList, pPre, dataInPtr);
	if (!sucesso)
	   return (-1);
	return (0);
}	

static bool insere_Lista (Lista* pList, Lista_node* pPre, void* dataInPtr) {
	Lista_node* pNew;

	if (!(pNew = (Lista_node*) malloc(sizeof(Lista_node))))
	   return false;

	pNew->dataPtr   = dataInPtr;
	pNew->link      = NULL;

	if (pPre == NULL) {
	    pNew->link       = pList->primeiro;
	    pList->primeiro      = pNew;
	    if (pList->contador == 0)
	       pList->ultimo = pNew;
	   }
	else {
	    pNew->link  = pPre->link;
	    pPre->link  = pNew;

	    if (pNew->link     == NULL)
	         pList->ultimo   =  pNew;
	   }

	(pList->contador)++;
	return true;
}

bool remove_No  (Lista*  pList, void*  keyPtr, void** dataOutPtr) {
	bool encontrado;

	Lista_node* pPre;
	Lista_node* pLoc;

	encontrado = _procura (pList, &pPre, &pLoc, keyPtr);
	if (encontrado)
	   exclui_Lista (pList, pPre, pLoc, dataOutPtr);

	return encontrado;
}

void exclui_Lista (Lista* pList, Lista_node* pPre, Lista_node* pLoc,  void** dataOutPtr) {
	*dataOutPtr = pLoc->dataPtr;
	if (pPre == NULL)
	   pList->primeiro = pLoc->link;
	else
	   pPre->link = pLoc->link;

	if (pLoc->link == NULL)
	    pList->ultimo = pPre;

	(pList->contador)--;
	free (pLoc);

	return;
}

bool procura_Lista (Lista*  pList, void* pArgu, void** pDataOut) {
	bool  encontrado;

	Lista_node* pPre;
	Lista_node* pLoc;

	encontrado = _procura (pList, &pPre, &pLoc, pArgu);
	if (encontrado)
	    *pDataOut = pLoc->dataPtr;
	else
	    *pDataOut = NULL;
	return encontrado;
}

static bool _procura (Lista*  pList, Lista_node** pPre, Lista_node** pLoc, void*  pArgu) {
#define COMPARA \
	( ((* pList->compara) (pArgu, (*pLoc)->dataPtr)) )

#define COMPARA_PROXIMO\
	((* pList->compara) (pArgu, pList->ultimo->dataPtr))

	int resultado;

	*pPre  = NULL;
	*pLoc  = pList->primeiro;
	if (pList->contador == 0)
	    return false;

	if ( COMPARA_PROXIMO > 0) {
	    *pPre = pList->ultimo;
	    *pLoc = NULL;
	    return false;
	   }

	while ((resultado = COMPARA) > 0 ) {
	    *pPre = *pLoc;
	    *pLoc = (*pLoc)->link;
	   } // while

	if (resultado == 0)
	   return true;
	else
	   return false;
}

bool recupera_No(Lista*  pList, void*  pArgu, void** dataOutPtr) {
	bool  encontrado;

	Lista_node* pPre;
	Lista_node* pLoc;
	
	printf("\n\nNo recuperado: %d \n", pArgu);
	
	encontrado = _procura(pList, &pPre, &pLoc, pArgu);
	if (encontrado) {
	    *dataOutPtr = pLoc->dataPtr;
	    return true;
	} 

	*dataOutPtr = NULL;
	return false;
}	

bool Lista_vazia(Lista* pList) {
	return (pList->contador == 0);
}

bool Lista_cheia(Lista* pList) {
	Lista_node* aux;
	
	if ((aux = (Lista_node*)malloc(sizeof(*(pList->primeiro))))) {
	    free (aux);
	    return false;
	}
		   
	return true;
}

int tamanho_Lista(Lista* pList) { 	
	return pList->contador;
}

bool percurso(Lista*  pList, int    fromWhere, void** dataPtrOut) {
	if (pList->contador == 0)
	    return false;

	if (fromWhere == 0) {
	    pList->pos  = pList->primeiro;
	    *dataPtrOut = pList->pos->dataPtr;
	    return true;
	   }else {
	    if (pList->pos->link == NULL)
	        return false;
	    else {
	        pList->pos  = pList->pos->link;
	        *dataPtrOut = pList->pos->dataPtr;
	        return true;
	       }
	   } 
}

Lista* destroi_Lista(Lista* pList) {
    Lista_node* deletePtr;

    if(pList) {
        while(pList->contador > 0) {
            free(pList->primeiro->dataPtr);

            deletePtr = pList->primeiro;
            pList->primeiro = pList->primeiro->link;
            pList->contador--;
            free(deletePtr);
        }
        free(pList);
    }
    return NULL;
}

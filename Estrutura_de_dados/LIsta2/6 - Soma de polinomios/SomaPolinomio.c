#include <stdio.h>
#include <stdlib.h>
#include "SomaPolinomio.h"

struct node {
    void* numero;
    void* expoente;
    struct node* link;
};

struct lista {
	int contador;
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

int adiciona_No (Lista* pList, void* numero, void* expoente) {
	bool encontrado;
	bool encontrado2;
	bool sucesso;

	Lista_node* pPre;
	Lista_node* pLoc;

	encontrado = _procura (pList, &pPre, &pLoc, numero);
	encontrado2 = _procura (pList, &pPre, &pLoc, expoente);
	if (encontrado && encontrado2)
	   return (+1);

	sucesso = insere_Lista (pList, pPre, numero, expoente);
	if (!sucesso)
	   return (-1);
	return (0);
}	

static bool insere_Lista (Lista* pList, Lista_node* pPre, void* numero, void* expoente) {
	
	Lista_node* pNew;

	if (!(pNew = (Lista_node*) malloc(sizeof(Lista_node)))){
		return false;
	}
 
	pNew->numero = numero;
	pNew->expoente = expoente;
	pNew->link = NULL;

	if (pPre == NULL) {
	    pNew->link = pList->primeiro;
	    pList->primeiro = pNew;
	    if (pList->contador == 0)
	       pList->ultimo = pNew;
	   }
	else {
	    pNew->link  = pPre->link;
	    pPre->link  = pNew;

	    if (pNew->link == NULL)
	         pList->ultimo =  pNew;
	   }

	(pList->contador)++;
	return true;
}

bool remove_No  (Lista*  pList, void*  keyPtr, void** numero, void** expoente) {
	bool encontrado;

	Lista_node* pPre;
	Lista_node* pLoc;

	encontrado = _procura (pList, &pPre, &pLoc, keyPtr);
	if (encontrado)
	   exclui_Lista (pList, pPre, pLoc, numero, expoente);

	return encontrado;
}

void exclui_Lista (Lista* pList, Lista_node* pPre, Lista_node* pLoc,  void** dataOutPtr, void** dataOutPtr2) {
	*dataOutPtr = pLoc->numero;
	*dataOutPtr = pLoc->expoente;
	
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

bool procura_Lista (Lista*  pList, void* pArgu, void* pArgu2, void** pDataOut, void** pDataOut2) {
	bool  encontrado;
	bool  encontrado2;
	
	Lista_node* pPre;
	Lista_node* pLoc;

	encontrado = _procura (pList, &pPre, &pLoc, pArgu);
	encontrado2 = _procura (pList, &pPre, &pLoc, pArgu2);
	if (encontrado && encontrado2) {
		*pDataOut = pLoc->numero;
	    *pDataOut2 = pLoc->expoente;
	} else {
		*pDataOut = NULL;
	    *pDataOut2 = NULL;	
	}
	    
	return encontrado;
}

static bool _procura (Lista*  pList, Lista_node** pPre, Lista_node** pLoc, void*  pArgu) {
#define COMPARA \
	( ((* pList->compara) (pArgu, (*pLoc)->numero)) )

#define COMPARA_PROXIMO\
	((* pList->compara) (pArgu, pList->ultimo->numero))

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
	   } 

	if (resultado == 0)
	   return true;
	else
	   return false;
}

bool recupera_No(Lista*  pList, void*  pArgu, void*  pArgu2, void** dataOutPtr, void** dataOutPtr2) {
	bool  encontrado;
	bool  encontrado2;

	Lista_node* pPre;
	Lista_node* pLoc;

	encontrado = _procura(pList, &pPre, &pLoc, pArgu);
	encontrado2 = _procura(pList, &pPre, &pLoc, pArgu2);
	if (encontrado && encontrado2) {
	    *dataOutPtr = pLoc->numero;
	    *dataOutPtr2 = pLoc->expoente;
	    return true;
	} 

	*dataOutPtr = NULL;
	*dataOutPtr2 = NULL;
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

bool percurso(Lista*  pList, int    fromWhere, void** dataPtrOut, void** dataPtrOut2) {
	if (pList->contador == 0)
	    return false;

	if (fromWhere == 0) {
	    pList->pos  = pList->primeiro;
	    *dataPtrOut = pList->pos->numero;
	    *dataPtrOut2 = pList->pos->expoente;
	    return true;
	   }else {
	    if (pList->pos->link == NULL)
	        return false;
	    else {
	        pList->pos  = pList->pos->link;
	        *dataPtrOut = pList->pos->numero;
	        *dataPtrOut2 = pList->pos->expoente;
	        return true;
	       }
	   } 
}

Lista* destroi_Lista(Lista* pList) {
    Lista_node* deletePtr;

    if(pList) {
        while(pList->contador > 0) {
            free(pList->primeiro->numero);
            free(pList->primeiro->expoente);

            deletePtr = pList->primeiro;
            pList->primeiro = pList->primeiro->link;
            pList->contador--;
            free(deletePtr);
        }
        free(pList);
    }
    return NULL;
}

Lista* soma_Polinomio(Lista* plist1, Lista* plist2, Lista* nova_Lista) {			

    Lista_node* nodeA = plist1->primeiro;											//inicia com o primeiro nó das listas
    Lista_node* nodeB = plist2->primeiro;											

    while (nodeA && nodeB) {														//executa enquanto não sao nulos
        int grauA = *((int*)nodeA->expoente);										//obtem os graus
        int grauB = *((int*)nodeB->expoente);										

        if (grauA > grauB) { 														//compara os graus
            adiciona_No(nova_Lista, nodeA->numero, nodeA->expoente);				//adiciona na nova lista se a maior que b
            nodeA = nodeA->link; 													//nodeA atualizado para o próximo
        } else if (grauA < grauB) {													//se menor
            adiciona_No(nova_Lista, nodeB->numero, nodeB->expoente);				//graub adiciona a nova lista
            nodeB = nodeB->link; 													//atualiza atualizado para o próximo
        } else {
            int* soma_Polinomio = (int*)malloc(sizeof(int)); 						//se igual soma
            *soma_Polinomio = *((int*)nodeA->numero) + *((int*)nodeB->numero); 		//soma os coeficientes dos termos apontados
            adiciona_No(nova_Lista, soma_Polinomio, nodeA->expoente); 				//e assim adicionado a nova lista
            nodeA = nodeA->link;													// nodeA e nodeB atualizados para apontar para os próximos nós
            nodeB = nodeB->link;
        }
    }

    while (nodeA != NULL) {
        adiciona_No(nova_Lista, nodeA->numero, nodeA->expoente);		//garantem que são adicionados todos os elmentos com expoentes diferentes sejam adicionados a nova lista
        nodeA = nodeA->link;
    }

    while (nodeB != NULL) {
        adiciona_No(nova_Lista, nodeB->numero, nodeB->expoente);					
        nodeB = nodeB->link;
    }

    return nova_Lista;									//retorna lista final
}

void mostra_Polinomio(Lista* polinomio) {								
    if (polinomio->primeiro == NULL) {									//verifica existe o primeiro elemento
        printf("Polinomio vazio\n");
    }

    Lista_node* current = polinomio->primeiro;							//primeiro no passa para o ponteiro current
    while (current != NULL) {
        int* numero = (int*)current->numero;							//recupera o valor do numero convertendo pra ponteiro de inteiro 
        int* expoente = (int*)current->expoente;						//recupera valor do expoente convertendo para ponteiro de inteiro
        printf("%dx^%d ", *numero, *expoente);							//mostra o polinomio
        if (current->link != NULL) {									//se ouver nó seguinte imprime o mais
            printf("+ ");
        }
        current = current->link;										//atualiza para o nó seguinte
    }
    printf("\n");
}

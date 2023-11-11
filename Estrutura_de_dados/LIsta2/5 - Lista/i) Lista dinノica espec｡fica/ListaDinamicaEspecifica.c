#include <stdio.h>
#include <stdlib.h>
#include "ListaDinamicaEspecifica.h"

struct node
{   int* dataPtr;													//ponteiro pro dado
    struct node* link;												//ponteiro próximo no
};

struct lista
{   int  contador;													// contedor
    Lista_node* pos;												// ponteiro posição atual
    Lista_node* primeiro;											// ponteiro primeiro da lista
    Lista_node* ultimo;												// ponteiro ultimo da lista
    int (*compara) (int* argu1, int* argu2);						// ordenar os elementos
};

Lista* cria_Lista (int (*compara) (int* argu1, int* argu2)) {		//cria a lista - recebeu o ponteiro de comparação e vai retornar um ponteiro recem criado
	Lista* l;														//cria ponteiro	

	l = (Lista*) malloc (sizeof(Lista));							//aloca memória
	if (l) {
	    l->primeiro = NULL;											//inicializa 
	    l->pos = NULL;
	    l->ultimo = NULL;
	    l->contador = 0;
	    l->compara = compara;
	   } 
	return l;														//retorna lista
}	

int adiciona_No (Lista* pList, int* dataInPtr) {					//adiciona novo nó
	bool encontrado;												
	bool sucesso;

	Lista_node* pPre;												//cria ponteiros para rastrear posição na lista
	Lista_node* pLoc;
	
	encontrado = _procura (pList, &pPre, &pLoc, dataInPtr);			//verifica se já existe na lista
	if (encontrado)
	   return (+1);

	sucesso = insere_Lista (pList, pPre, dataInPtr);				
	if (!sucesso)													//insere na lista
	   return (-1);
	return (0);
}	

static bool insere_Lista (Lista* pList, Lista_node* pPre, int* dataInPtr) {		//insere elementos na lista
	Lista_node* pNew;															//ponteiro para novo nó

	if (!(pNew = (Lista_node*) malloc(sizeof(Lista_node))))
	   return false;

	pNew->dataPtr   = dataInPtr;												//dados entram como dados do novo nó										
	pNew->link      = NULL;														//NULL pq é ultimo nó da lista

	if (pPre == NULL) {
	    pNew->link = pList->primeiro;											//se nulo o novo nó link passa a ser o primeiro da lista
	    pList->primeiro = pNew;													//ponteiro primerio passa a apontar para um novo nó
	    if (pList->contador == 0)												//se lista vazia
	       pList->ultimo = pNew;												//o ultimo nó também apontará para o novo nó pois só existira ele na lista
	   }
	else {
	    pNew->link = pPre->link;												//link do novo nó será definido como pPre->link
	    pPre->link = pNew;														//e o pPrelink passa a apontar para um novo nó

	    if (pNew->link == NULL)													//se o link nulo
	         pList->ultimo =  pNew;												//pList->ultimo passa a apontar para um novo nó
	   }

	(pList->contador)++;														// contador incrementa
	return true;
}

bool remove_No  (Lista*  pList, int*  keyPtr, int** dataOutPtr) {				//remove no
	bool encontrado;

	Lista_node* pPre;															//cria ponteiros para rastrear posição na lista
	Lista_node* pLoc;

	encontrado = _procura (pList, &pPre, &pLoc, keyPtr);						//verifica se já existe na lista o elemento especificado pelo keyPtr
	if (encontrado)
	   exclui_Lista (pList, pPre, pLoc, dataOutPtr);							//elimina no da lista

	return encontrado;
}

void exclui_Lista (Lista* pList, Lista_node* pPre, Lista_node* pLoc,  int** dataOutPtr) {	// remover no especifico
	*dataOutPtr = pLoc->dataPtr;															// valor do ponteiro dataPrt vai para o endereço apontado dataOutPtr
	if (pPre == NULL)																		
	   pList->primeiro = pLoc->link;														// Ponteiro primeiro atualizado para nó seguinte
	else
	   pPre->link = pLoc->link;																//pPre-> link atualiza para apontar para nó seguinte pulando o nó a ser excluido
	if (pLoc->link == NULL)																	
	    pList->ultimo = pPre;																//pList->ultimo atualiza para apontar para o nó anterior
	(pList->contador)--;																	//contador decrementa
	free (pLoc);																			//libera memória do nó a ser excluido
}

bool procura_Lista (Lista*  pList, int* pArgu, int** pDataOut) {							//procura na lista
	bool  encontrado;													
	
	Lista_node* pPre;																		//cria ponteiros para rastrear posição na lista
	Lista_node* pLoc;

	encontrado = _procura (pList, &pPre, &pLoc, pArgu);										//verifica se já existe na lista o elemento especificado pelo pArgu
	if (encontrado)	
	    *pDataOut = pLoc->dataPtr;															//Dados do pLoc (dado encontrado) é atribuido a *pDataOut
	else
	    *pDataOut = NULL;																	//Não encontrado
	return encontrado;
}

static bool _procura (Lista*  pList, Lista_node** pPre, Lista_node** pLoc, int*  pArgu) {	//auxiliar a busca por elementos da lista 
#define COMPARA \
	( ((* pList->compara) (pArgu, (*pLoc)->dataPtr)) )										//usado para comparar dados do elemento atual com o procurado

#define COMPARA_PROXIMO\
	((* pList->compara) (pArgu, pList->ultimo->dataPtr))									//compara os dados do elemento seguinte ao ultimo elmento da lista com o dado procurado

	int resultado;

	*pPre  = NULL;																			//inicializa os ponteiros
	*pLoc  = pList->primeiro;																//primeiro nó na lista
	if (pList->contador == 0)																//verifica se está vazia
	    return false;

	if (COMPARA_PROXIMO > 0) {																//elemento procurado maior que o elemento da lista
	    *pPre = pList->ultimo;																//além do ultimo da lista, pPre é definido como ultimo da lista
	    *pLoc = NULL;																		//ploc definido como NULL(nao existe)
	    return false;
	   }

	while ((resultado = COMPARA) > 0 ) {													//elemento atual é menor que o procurado
	    *pPre = *pLoc;																		//pPre recebe valor do pLoc
	    *pLoc = (*pLoc)->link;																//pLoc aponta para o próximo nó da lista
	   } 

	if (resultado == 0)
	   return true;																			//elemento encontrado
	else
	   return false;																		//elemento não encontrado
}

bool recupera_No(Lista*  pList, int*  pArgu, int** dataOutPtr) {							//busca na lista o nó correspondente ao pArgu
	bool  encontrado;	

	Lista_node* pPre;																		//cria ponteiros para rastrear posição na lista
	Lista_node* pLoc;

	encontrado = _procura(pList, &pPre, &pLoc, pArgu);										//verifica se já existe na lista o elemento especificado pelo pArgu
	if (encontrado) {
	    *dataOutPtr = pLoc->dataPtr;														//dataOutPtr vai receber oendereço do valor encontrado
	    return true;
	} 

	*dataOutPtr = NULL;																		//caso nã definido como NULL
	return false;
}	

bool Lista_vazia(Lista* pList) {															//Verifica se contador ta em zero
	return (pList->contador == 0);
}

bool Lista_cheia(Lista* pList) {															//verifica se a lista ta cheia
	Lista_node* aux;
		
	if ((aux = (Lista_node*)malloc(sizeof(*(pList->primeiro))))) {							//tenta alocar memória se puder a lista ainda não ta cheia
	    free (aux);																			//libera espaço alocado
	    return false;
	}
		   
	return true;
}

int tamanho_Lista(Lista* pList) { 															//verifica numero do contador
	return pList->contador;	
}

bool percurso(Lista*  pList, int fromWhere, int** dataPtrOut) {								//percorre a lista e retorna um nó especifico por fromwhere
	if (pList->contador == 0)																//verifica lista vazia
	    return false;

	if (fromWhere == 0) {																	//percurso começa no primeiro nó
	    pList->pos  = pList->primeiro;														//pList-> pos atualizado para apontar pro endereço do primeiro nó
	    *dataPtrOut = pList->pos->dataPtr;													//dataPtrOut aponta pro valor do primerio nó
	    return true;
	   }else {
		    if (pList->pos->link == NULL)													//verifica se possui um nó seguinte
		        return false;
		    else {
		        pList->pos  = pList->pos->link;												//pList atualizado para apontar para o endereço do nó seguinte
		        *dataPtrOut = pList->pos->dataPtr;											//dataPtrOut aponta pro valor do nó atualizado
		        return true;
		       }
	   } 
}

Lista* destroi_Lista(Lista* pList) {														//libera espaço de memória alocada para a lista
    Lista_node* deletePtr;																	//criação de ponteiro auxiliar

    if(pList) {																				
        while(pList->contador > 0) {														//enquanto tiver elementos na lista
            free(pList->primeiro->dataPtr);													//libera memória alocada para os dados do primeiro

            deletePtr = pList->primeiro;													//depois o deletePtr vai receber o prime
            pList->primeiro = pList->primeiro->link;										//primerio recebe o próximo dele
            pList->contador--;																//decrementa o contador
            free(deletePtr);																//libera memória alocada pro ponteiro auxiliar
        }
        free(pList);																		//libera memória alocada pra lista
    }
    return NULL;
}

void print_Lista(Lista* minhaLista) {														//mostra a lista
    Lista_node* showList = minhaLista->primeiro;											//ponteiro que aponta o primeiro nó

    while(showList != NULL) {																
        int getValue = *(showList->dataPtr);												//getValue recebe valor apontado pelo dataPtr
        printf("%d ", getValue);															//mostra esse valor
        showList = showList->link;															//showlist passa a apontar para o próximo nó da lista
    }
    printf("\n");
}

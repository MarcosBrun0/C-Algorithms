#include <stdio.h>
#include <stdlib.h>
#include "ListaDinamicaEspecifica.h"

struct node
{   int* dataPtr;													//ponteiro pro dado
    struct node* link;												//ponteiro pr�ximo no
};

struct lista
{   int  contador;													// contedor
    Lista_node* pos;												// ponteiro posi��o atual
    Lista_node* primeiro;											// ponteiro primeiro da lista
    Lista_node* ultimo;												// ponteiro ultimo da lista
    int (*compara) (int* argu1, int* argu2);						// ordenar os elementos
};

Lista* cria_Lista (int (*compara) (int* argu1, int* argu2)) {		//cria a lista - recebeu o ponteiro de compara��o e vai retornar um ponteiro recem criado
	Lista* l;														//cria ponteiro	

	l = (Lista*) malloc (sizeof(Lista));							//aloca mem�ria
	if (l) {
	    l->primeiro = NULL;											//inicializa 
	    l->pos = NULL;
	    l->ultimo = NULL;
	    l->contador = 0;
	    l->compara = compara;
	   } 
	return l;														//retorna lista
}	

int adiciona_No (Lista* pList, int* dataInPtr) {					//adiciona novo n�
	bool encontrado;												
	bool sucesso;

	Lista_node* pPre;												//cria ponteiros para rastrear posi��o na lista
	Lista_node* pLoc;
	
	encontrado = _procura (pList, &pPre, &pLoc, dataInPtr);			//verifica se j� existe na lista
	if (encontrado)
	   return (+1);

	sucesso = insere_Lista (pList, pPre, dataInPtr);				
	if (!sucesso)													//insere na lista
	   return (-1);
	return (0);
}	

static bool insere_Lista (Lista* pList, Lista_node* pPre, int* dataInPtr) {		//insere elementos na lista
	Lista_node* pNew;															//ponteiro para novo n�

	if (!(pNew = (Lista_node*) malloc(sizeof(Lista_node))))
	   return false;

	pNew->dataPtr   = dataInPtr;												//dados entram como dados do novo n�										
	pNew->link      = NULL;														//NULL pq � ultimo n� da lista

	if (pPre == NULL) {
	    pNew->link = pList->primeiro;											//se nulo o novo n� link passa a ser o primeiro da lista
	    pList->primeiro = pNew;													//ponteiro primerio passa a apontar para um novo n�
	    if (pList->contador == 0)												//se lista vazia
	       pList->ultimo = pNew;												//o ultimo n� tamb�m apontar� para o novo n� pois s� existira ele na lista
	   }
	else {
	    pNew->link = pPre->link;												//link do novo n� ser� definido como pPre->link
	    pPre->link = pNew;														//e o pPrelink passa a apontar para um novo n�

	    if (pNew->link == NULL)													//se o link nulo
	         pList->ultimo =  pNew;												//pList->ultimo passa a apontar para um novo n�
	   }

	(pList->contador)++;														// contador incrementa
	return true;
}

bool remove_No  (Lista*  pList, int*  keyPtr, int** dataOutPtr) {				//remove no
	bool encontrado;

	Lista_node* pPre;															//cria ponteiros para rastrear posi��o na lista
	Lista_node* pLoc;

	encontrado = _procura (pList, &pPre, &pLoc, keyPtr);						//verifica se j� existe na lista o elemento especificado pelo keyPtr
	if (encontrado)
	   exclui_Lista (pList, pPre, pLoc, dataOutPtr);							//elimina no da lista

	return encontrado;
}

void exclui_Lista (Lista* pList, Lista_node* pPre, Lista_node* pLoc,  int** dataOutPtr) {	// remover no especifico
	*dataOutPtr = pLoc->dataPtr;															// valor do ponteiro dataPrt vai para o endere�o apontado dataOutPtr
	if (pPre == NULL)																		
	   pList->primeiro = pLoc->link;														// Ponteiro primeiro atualizado para n� seguinte
	else
	   pPre->link = pLoc->link;																//pPre-> link atualiza para apontar para n� seguinte pulando o n� a ser excluido
	if (pLoc->link == NULL)																	
	    pList->ultimo = pPre;																//pList->ultimo atualiza para apontar para o n� anterior
	(pList->contador)--;																	//contador decrementa
	free (pLoc);																			//libera mem�ria do n� a ser excluido
}

bool procura_Lista (Lista*  pList, int* pArgu, int** pDataOut) {							//procura na lista
	bool  encontrado;													
	
	Lista_node* pPre;																		//cria ponteiros para rastrear posi��o na lista
	Lista_node* pLoc;

	encontrado = _procura (pList, &pPre, &pLoc, pArgu);										//verifica se j� existe na lista o elemento especificado pelo pArgu
	if (encontrado)	
	    *pDataOut = pLoc->dataPtr;															//Dados do pLoc (dado encontrado) � atribuido a *pDataOut
	else
	    *pDataOut = NULL;																	//N�o encontrado
	return encontrado;
}

static bool _procura (Lista*  pList, Lista_node** pPre, Lista_node** pLoc, int*  pArgu) {	//auxiliar a busca por elementos da lista 
#define COMPARA \
	( ((* pList->compara) (pArgu, (*pLoc)->dataPtr)) )										//usado para comparar dados do elemento atual com o procurado

#define COMPARA_PROXIMO\
	((* pList->compara) (pArgu, pList->ultimo->dataPtr))									//compara os dados do elemento seguinte ao ultimo elmento da lista com o dado procurado

	int resultado;

	*pPre  = NULL;																			//inicializa os ponteiros
	*pLoc  = pList->primeiro;																//primeiro n� na lista
	if (pList->contador == 0)																//verifica se est� vazia
	    return false;

	if (COMPARA_PROXIMO > 0) {																//elemento procurado maior que o elemento da lista
	    *pPre = pList->ultimo;																//al�m do ultimo da lista, pPre � definido como ultimo da lista
	    *pLoc = NULL;																		//ploc definido como NULL(nao existe)
	    return false;
	   }

	while ((resultado = COMPARA) > 0 ) {													//elemento atual � menor que o procurado
	    *pPre = *pLoc;																		//pPre recebe valor do pLoc
	    *pLoc = (*pLoc)->link;																//pLoc aponta para o pr�ximo n� da lista
	   } 

	if (resultado == 0)
	   return true;																			//elemento encontrado
	else
	   return false;																		//elemento n�o encontrado
}

bool recupera_No(Lista*  pList, int*  pArgu, int** dataOutPtr) {							//busca na lista o n� correspondente ao pArgu
	bool  encontrado;	

	Lista_node* pPre;																		//cria ponteiros para rastrear posi��o na lista
	Lista_node* pLoc;

	encontrado = _procura(pList, &pPre, &pLoc, pArgu);										//verifica se j� existe na lista o elemento especificado pelo pArgu
	if (encontrado) {
	    *dataOutPtr = pLoc->dataPtr;														//dataOutPtr vai receber oendere�o do valor encontrado
	    return true;
	} 

	*dataOutPtr = NULL;																		//caso n� definido como NULL
	return false;
}	

bool Lista_vazia(Lista* pList) {															//Verifica se contador ta em zero
	return (pList->contador == 0);
}

bool Lista_cheia(Lista* pList) {															//verifica se a lista ta cheia
	Lista_node* aux;
		
	if ((aux = (Lista_node*)malloc(sizeof(*(pList->primeiro))))) {							//tenta alocar mem�ria se puder a lista ainda n�o ta cheia
	    free (aux);																			//libera espa�o alocado
	    return false;
	}
		   
	return true;
}

int tamanho_Lista(Lista* pList) { 															//verifica numero do contador
	return pList->contador;	
}

bool percurso(Lista*  pList, int fromWhere, int** dataPtrOut) {								//percorre a lista e retorna um n� especifico por fromwhere
	if (pList->contador == 0)																//verifica lista vazia
	    return false;

	if (fromWhere == 0) {																	//percurso come�a no primeiro n�
	    pList->pos  = pList->primeiro;														//pList-> pos atualizado para apontar pro endere�o do primeiro n�
	    *dataPtrOut = pList->pos->dataPtr;													//dataPtrOut aponta pro valor do primerio n�
	    return true;
	   }else {
		    if (pList->pos->link == NULL)													//verifica se possui um n� seguinte
		        return false;
		    else {
		        pList->pos  = pList->pos->link;												//pList atualizado para apontar para o endere�o do n� seguinte
		        *dataPtrOut = pList->pos->dataPtr;											//dataPtrOut aponta pro valor do n� atualizado
		        return true;
		       }
	   } 
}

Lista* destroi_Lista(Lista* pList) {														//libera espa�o de mem�ria alocada para a lista
    Lista_node* deletePtr;																	//cria��o de ponteiro auxiliar

    if(pList) {																				
        while(pList->contador > 0) {														//enquanto tiver elementos na lista
            free(pList->primeiro->dataPtr);													//libera mem�ria alocada para os dados do primeiro

            deletePtr = pList->primeiro;													//depois o deletePtr vai receber o prime
            pList->primeiro = pList->primeiro->link;										//primerio recebe o pr�ximo dele
            pList->contador--;																//decrementa o contador
            free(deletePtr);																//libera mem�ria alocada pro ponteiro auxiliar
        }
        free(pList);																		//libera mem�ria alocada pra lista
    }
    return NULL;
}

void print_Lista(Lista* minhaLista) {														//mostra a lista
    Lista_node* showList = minhaLista->primeiro;											//ponteiro que aponta o primeiro n�

    while(showList != NULL) {																
        int getValue = *(showList->dataPtr);												//getValue recebe valor apontado pelo dataPtr
        printf("%d ", getValue);															//mostra esse valor
        showList = showList->link;															//showlist passa a apontar para o pr�ximo n� da lista
    }
    printf("\n");
}

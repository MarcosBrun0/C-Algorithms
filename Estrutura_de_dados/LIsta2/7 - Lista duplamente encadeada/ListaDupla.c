#include <stdio.h>
#include <stdlib.h>
#include "ListaDupla.h"

	struct node{   
		void* dataPtr;
	    struct node* link;
	    struct node* prev;
	};

	struct lista{   
		int contador;
	    Lista_no* pos;
	    Lista_no* primeiro;
	    Lista_no* ultimo;
	    int (*compara) (void* argu1, void* argu2);
	};

	struct censo{
        short   ano;
        char    cidade[STR_MAX];
        unsigned long populacao;
    };

Lista* cria_Lista(int (*compara) (void* argu1, void* argu2)){
	Lista* l;

	l = (Lista*) malloc (sizeof (Lista));
	if (l){
	    l->primeiro    = NULL;
	    l->pos     = NULL;
	    l->ultimo    = NULL;
	    l->contador   = 0;
	    l->compara = compara;
	   }

	return l;
}

int adiciona_No (Lista* pList, void* dataInPtr){

	bool encontrado;
	bool sucesso;

	Lista_no* pPre;
	Lista_no* pLoc;

	encontrado = _procura (pList, &pPre, &pLoc, dataInPtr);
	if (encontrado)
	   return (+1);

	sucesso = insere_Lista (pList, pPre, dataInPtr);
	if (!sucesso)
	   return (-1);
	return (0);
}

int populacao (void* pPopulacao1, void* pPopulacao2){							
	int resultado;
	int populacao1,populacao2;													
	char nome1[100], nome2[100];												
	int ano1, ano2;																

	populacao1 = ((Censo*)pPopulacao1)->populacao;								// recebe a população da estrutura
	populacao2 = ((Censo*)pPopulacao2)->populacao;								
	
	strcpy(nome1, ((Censo*)pPopulacao1)->cidade);								// função pra copiar o nome das cidades
	strcpy(nome2, ((Censo*)pPopulacao2)->cidade);								

	ano1 = ((Censo*)pPopulacao1)->ano;											//recebe a ano da estrutura
	ano2 = ((Censo*)pPopulacao2)->ano;											

	if(strcasecmp(nome1,nome2) == 0 && ano1 == ano2)							// compara valor se são iguais ignorando maiuscula e minuscula
		resultado = 0;
	else if (populacao1 < populacao2)											
	    resultado = +1;
	else
	    resultado = -1;
}

Lista* cria_lista (){															

	FILE* file;
	Lista* l;

	char nome[100];
	int  pop;
	int  ano;
	int  res;

	Censo* censo;
	char c;

	l = cria_Lista (populacao);
	if (!l){
		printf("\aErro na criacao da lista...\n");
	    exit (100);
	}

	file = fopen("Censo.txt", "r");
	if (!file)	{
		printf("\aErro na abertura do arquivo...\n");
	    exit (110);
	}

	while(fscanf(file,"\"%[^\"]\"\t%hd\t%lu\n",nome, &ano, &pop) != EOF) {    //formato para extrair do arquivo
		censo = (Censo*) malloc(sizeof(Censo));
	    if (!(censo)) {
	    	printf("\aErro na alocacao de memoria...\n");
	        exit (100);
		}
		strcpy(censo->cidade, nome); 
		censo->populacao = pop;
		censo->ano = ano;

	    res = adiciona_No (l, censo);
	    if (res != 0)
	        if (res == -1)
	            printf("Overflow de memoria...\a\n"),
	                    exit (120);
	        else
	            printf("Valor duplicado %lu nao adicionado...\n\a",
	                    censo->populacao);
	}
	fclose(file);

	return l;
}

static bool insere_Lista (Lista* pList, Lista_no* pPre, void* dataInPtr){								
	Lista_no* pNew;																//declara ponteiro pra novo no

	if (!(pNew = (Lista_no*) malloc(sizeof(Lista_no))))
	   return false;

	pNew->dataPtr = dataInPtr;													//inicializa os ponteiros
	pNew->link = NULL;
	pNew->prev = NULL;

	if (pPre == NULL) {															
        pNew->link = pList->primeiro;											//link o pNew aponta para primeiro no da lista
        if (pList->primeiro != NULL) {											//se o primeiro já existir prev aponta para o novo nó
            pList->primeiro->prev = pNew;
        }
        pList->primeiro = pNew;													//primeiro da lista vai apontar para novo nó
        if (pList->contador == 0) {												//se vazia o ultimo também vai apontar para novo nó
            pList->ultimo = pNew;
        }
    } else {
        pNew->link = pPre->link;												//link do novo nó aponta para o nó originalmente após pPre
        pNew->prev = pPre;														//o campo prev do novo nó vai apontar para pPre
        pPre->link = pNew;														//link de pPre vai ser atualizado para apontar para novo nó

        if (pNew->link == NULL) {												
            pList->ultimo = pNew;												// ultimo vai apontar para novo nó
        } else {
            pNew->link->prev = pNew;											//prev do nó seguinte ao novo nó é atualizado para apontar pra o novo nó
        }
    }

    (pList->contador)++;
    return true;
}

bool remove_No  (Lista*  pList, void*  keyPtr, void** dataOutPtr){
	bool encontrado;

	Lista_no* pPre;
	Lista_no* pLoc;

	encontrado = _procura (pList, &pPre, &pLoc, keyPtr);
	if (encontrado)
	   remove_Lista (pList, pPre, pLoc, dataOutPtr);

	return encontrado;
}

void remove_Lista (Lista* pList, Lista_no*  pPre, Lista_no* pLoc,  void** dataOutPtr) {
	*dataOutPtr = pLoc->dataPtr;
	    if (pPre == NULL) {
        pList->primeiro = pLoc->link;
        if (pLoc->link != NULL) {
            pLoc->link->prev = NULL;
        }
    } else {
        pPre->link = pLoc->link;
        if (pLoc->link != NULL) {
            pLoc->link->prev = pPre;
        }
    }

    if (pLoc->link == NULL) {
        pList->ultimo = pPre;
    }

    (pList->contador)--;
    free(pLoc);
}

bool procura_Lista (Lista*  pList, void* pArgu, void** pDataOut){
	bool  encontrado;

	Lista_no* pPre;
	Lista_no* pLoc;

	encontrado = _procura (pList, &pPre, &pLoc, pArgu);
	if (encontrado)
	    *pDataOut = pLoc->dataPtr;
	else
	    *pDataOut = NULL;
	return encontrado;
}

static bool _procura (Lista*  pList, Lista_no** pPre, Lista_no** pLoc,  void*  pArgu){
#define COMPARA \
	( ((* pList->compara) (pArgu, (*pLoc)->dataPtr)) )

#define COMPARA_ULTIMO \
	((* pList->compara) (pArgu, pList->ultimo->dataPtr))

	int resultado;

	*pPre  = NULL;
	*pLoc  = pList->primeiro;
	if (pList->contador == 0)
	    return false;

	if (COMPARA_ULTIMO > 0){
	    *pPre = pList->ultimo;
	    *pLoc = NULL;
	    return false;
	} // if

	while ( (resultado = COMPARA) > 0 ){
	    *pPre = *pLoc;
	    *pLoc = (*pLoc)->link;
	   }

	if (resultado == 0)
	   return true;
	else
	   return false;
}

bool recupera_No (Lista*  pList, void*  pArgu, void** dataOutPtr){
	bool  encontrado;

	Lista_no* pPre;
	Lista_no* pLoc;

	encontrado = _procura (pList, &pPre, &pLoc, pArgu);
	if (encontrado){
	    *dataOutPtr = pLoc->dataPtr;
	    return true;
	} 

	*dataOutPtr = NULL;
	return false;
}

bool Lista_vazia (Lista* pList){
	return (pList->contador == 0);
}

bool Lista_cheia (Lista* pList){
Lista_no* temp;
	if ((temp = (Lista_no*)malloc(sizeof(*(pList->primeiro))))){
	    free (temp);
	    return false;
	}

	return true;
}

int tamanho_Lista(Lista* pList){ 	
	return pList->contador;
}

bool percorreDecrescente (Lista*  pList, int fromWhere, void** dataPtrOut) {
	if (pList->contador == 0)
	    return false;

	if (fromWhere == 0) {
	    pList->pos  = pList->primeiro;
	    *dataPtrOut = pList->pos->dataPtr;
	    return true;
	}else{
	    if (pList->pos->link == NULL){
			return false;
		}  
	    else{
	        pList->pos  = pList->pos->link;
	        *dataPtrOut = pList->pos->dataPtr;
	        return true;
	    }
	} 
}

bool percorreCrescente (Lista*  pList, int fromWhere, void** dataPtrOut) {
	if (pList->contador == 0)
	    return false;

	if (fromWhere == 0) {
	    pList->pos  = pList->ultimo;
	    *dataPtrOut = pList->pos->dataPtr;
	    return true;
	}else{
	    if (pList->pos->prev == NULL){
			return false;
		}  
	    else{
	        pList->pos = pList->pos->prev;
	        *dataPtrOut = pList->pos->dataPtr;
	        return true;
	    }
	} 
}

Lista* destroi_Lista (Lista* pList){
	Lista_no* deletePtr;
	
	if (pList) {
	    while (pList->contador > 0) {
	        free (pList->primeiro->dataPtr);
	        
	        deletePtr = pList->primeiro;
	        pList->primeiro = pList->primeiro->link;
	        pList->contador--;
	        free (deletePtr);
	       } 
	    free (pList);
	   } 
	return NULL;
}

void mostra_Lista(Lista* l, int x){
	Censo* censo;

	if (tamanho_Lista (l) == 0)
	   printf("Lista vazia...\n\a");
	else {
		if (x == 1){
			printf("\nLista ordenada da populacao de forma crescente: \n\n");
		    percorreCrescente (l, 0, (void**)&censo);													//imprime primeiro elemento
		    do{																							
		       printf("%s - %lu\n",censo->cidade, censo->populacao);
		    } while (percorreCrescente (l, 1, (void**)&censo)); 										//posiciona o ponteiro no próximo elemento
		}else{
		    printf("\nLista ordenada da populacao de forma decrescente: \n\n");
		    percorreDecrescente (l, 0, (void**)&censo);													
		    do{
		       printf("%s - %lu\n",censo->cidade, censo->populacao);
		    } while (percorreDecrescente (l, 1, (void**)&censo)); 										
		}
	}
}

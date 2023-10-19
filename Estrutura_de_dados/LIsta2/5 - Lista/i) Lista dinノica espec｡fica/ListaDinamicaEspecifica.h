#ifndef LISTADINAMICAESPECIFICA_H_INCLUDED    //verificar conteudo não está incluido mais de uma vez - macro
#define LISTADINAMICAESPECIFICA_H_INCLUDED

#include <stdbool.h>

typedef struct node Lista_node;
typedef struct lista Lista;

Lista* cria_Lista(int (*compara) (int* argu1, int* argu2));                  
Lista* destroi_Lista(Lista* l);

int   adiciona_No(Lista* pList, int* dataInPtr);
bool  remove_No(Lista*  pList, int*  keyPtr, int** dataOutPtr);
bool  recupera_No(Lista*  pList, int*  pArgu, int** dataOutPtr);                  
bool  procura_Lista(Lista*  pList, int*  pArgu, int** pDataOut);
bool  percurso(Lista*  pList, int fromWhere, int** dataOutPtr);
int   tamanho_Lista(Lista*  pList);
bool  Lista_vazia(Lista*  pList);
bool  Lista_cheia(Lista*  pList);
static bool insere_Lista(Lista* pList, Lista_node* pPre, int* dataInPtr);
static void exclui_Lista(Lista*  pList, Lista_node*  pPre, Lista_node*  pLoc, int** dataOutPtr);
static bool _procura(Lista*  pList, Lista_node** pPre, Lista_node** pLoc, int*  pArgu);

#endif

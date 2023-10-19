#ifndef LISTADINAMICAESPECIFICA_H_INCLUDED
#define LISTADINAMICAESPECIFICA_H_INCLUDED

#include <stdbool.h>

typedef struct node Lista_node;
typedef struct lista Lista;

Lista* cria_Lista(int (*compara) (void* argu1, void* argu2));                  
Lista* destroi_Lista(Lista* l);
int   adiciona_No(Lista* pList, void* dataInPtr);
bool  remove_No(Lista*  pList, void*  keyPtr, void** dataOutPtr);
bool  recupera_No(Lista*  pList, void*  pArgu, void** dataOutPtr);                 
bool  procura_Lista(Lista*  pList, void*  pArgu, void** pDataOut);
bool  percurso(Lista*  pList, int fromWhere, void** dataOutPtr);
int   tamanho_Lista(Lista*  pList);
bool  Lista_vazia(Lista*  pList);
bool  Lista_cheia(Lista*  pList);
static bool insere_Lista(Lista* pList, Lista_node* pPre, void* dataInPtr);
static void exclui_Lista(Lista*  pList, Lista_node*  pPre, Lista_node*  pLoc, void** dataOutPtr);
static bool _procura(Lista*  pList, Lista_node** pPre, Lista_node** pLoc, void*  pArgu);

#endif

#ifndef LINKLISTADT_H_INCLUDED
#define LINKLISTADT_H_INCLUDED

#include <stdbool.h>


typedef struct node Lista_node;
typedef struct lista Lista;

Lista* cria_Lista (int (*compara) (void* argu1, void* argu2));
int adiciona_No (Lista* pList, void* numero, void* expoente);
static bool insere_Lista (Lista* pList, Lista_node* pPre, void* numero, void* expoente);
bool remove_No (Lista*  pList, void*  keyPtr, void** numero, void** expoente);
void exclui_Lista (Lista* pList, Lista_node* pPre, Lista_node* pLoc,  void** dataOutPtr, void** dataOutPtr2);
bool procura_Lista (Lista*  pList, void* pArgu, void* pArgu2, void** pDataOut, void** pDataOut2);
static bool _procura (Lista*  pList, Lista_node** pPre, Lista_node** pLoc, void*  pArgu);
bool recupera_No(Lista*  pList, void*  pArgu, void*  pArgu2, void** dataOutPtr, void** dataOutPtr2);
bool Lista_vazia(Lista* pList);
bool Lista_cheia(Lista* pList);
int tamanho_Lista(Lista* pList);
Lista* destroi_Lista(Lista* pList);

bool percurso(Lista*  pList, int fromWhere, void** dataPtrOut, void** dataPtrOut2); 
Lista* soma_Polinomio(Lista* plist1, Lista* plist2, Lista* nova_Lista); 			
void mostra_Polinomio(Lista* polinomio);	

#endif 

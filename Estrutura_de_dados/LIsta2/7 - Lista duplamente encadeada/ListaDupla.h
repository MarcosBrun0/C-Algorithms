#include <stdbool.h>
#define STR_MAX 500

typedef struct node Lista_no;
typedef struct lista Lista;
typedef struct censo Censo;

	Lista* cria_Lista(int (*compare)(void* argu1, void* argu2));
	Lista* destroyList(Lista* l);

	int adiciona_No(Lista* pList, void* dataInPtr);
	bool remove_No(Lista* pList, void* keyPtr, void** dataOutPtr);
	bool procura_Lista(Lista* pList, void* pArgu, void** pDataOut);
	bool recupera_No(Lista* pList, void* pArgu, void** dataOutPtr);
	bool percorreCrescente(Lista* pList, int fromWhere, void** dataPtrOut);
	bool percorreDecrescente(Lista* pList, int fromWhere, void** dataPtrOut);
	int tamanho_Lista(Lista* pList);
	bool Lista_vazia(Lista* pList);
	bool Lista_cheia(Lista* pList);
	static bool insere_Lista(Lista* pList, Lista_no* pPre, void* dataInPtr);
	static void remove_Lista(Lista* pList, Lista_no* pPre, Lista_no* pLoc, void** dataOutPtr);
	static bool _procura(Lista* pList, Lista_no** pPre, Lista_no** pLoc, void* pArgu);
    Lista* cria_lista();
    void mostra_Lista(Lista* l, int x);
	int populacao (void* pPopulacao1, void* pPopulacao2);

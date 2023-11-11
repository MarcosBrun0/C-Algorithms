typedef struct node Pilha_node;
typedef struct pilha Pilha;

Pilha* cria_Pilha();
int Pilha_vazia(Pilha* p);
int Pilha_cheia(Pilha* p);
int insere_Pilha(Pilha* p, void* dataInPtr);
void* remove_Pilha(Pilha* p);
void* topo_Pilha(Pilha* p);
int tamanho_Pilha(Pilha* p);
Pilha* destroi_Pilha(Pilha* p);

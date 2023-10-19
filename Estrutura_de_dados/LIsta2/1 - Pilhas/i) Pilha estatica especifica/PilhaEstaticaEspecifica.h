#define TAMANHO 30

typedef struct pilha Pilha;

Pilha* cria_Pilha();
int Pilha_vazia(Pilha *p);
int Pilha_cheia(Pilha *p);
int insere_Pilha(Pilha *p, int n);
int remove_Pilha(Pilha *p);
int topo_Pilha(Pilha *p);
int tamanho_Pilha(Pilha *p);
int destroi_Pilha(Pilha *p);

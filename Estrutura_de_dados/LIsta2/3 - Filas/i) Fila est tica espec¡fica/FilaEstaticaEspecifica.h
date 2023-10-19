#define TAMANHO 10

typedef struct fila Fila;

Fila* cria_Fila();
int Fila_vazia(Fila* f);
int Fila_cheia(Fila* f);
int enfilera_Fila(Fila* f, int data);
int desenfilera_Fila(Fila* f);
int tamanho_Fila(Fila* f);
int primeiro_Fila(Fila* f);
void destroi_Fila(Fila* f);

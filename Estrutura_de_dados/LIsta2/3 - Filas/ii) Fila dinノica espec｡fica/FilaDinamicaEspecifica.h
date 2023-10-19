typedef struct node Fila_node;
typedef struct fila Fila;

Fila* cria_Fila();
int Fila_vazia(Fila* f);
int Fila_cheia(Fila* f);
int enfilera_Fila(Fila* f, int* itemPtr);
int desenfilera_Fila(Fila* f, int**itemPtr);
int tamanho_Fila(Fila* f);
int primeiro_Fila(Fila* l, int** itemPtr);
int ultimo_Fila(Fila* f, int**itemPtr);
Fila* destroi_Fila(Fila* f);

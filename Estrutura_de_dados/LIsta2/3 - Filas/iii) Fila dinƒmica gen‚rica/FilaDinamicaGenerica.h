typedef struct node Fila_node;
typedef struct fila Fila;

Fila* cria_Fila();
bool Fila_vazia(Fila* f);
bool Fila_cheia(Fila* f);
bool enfilera_Fila(Fila* f, void* itemPtr);
bool desenfilera_Fila(Fila* f, void**itemPtr);
int tamanho_Fila(Fila* f);
bool primeiro_Fila(Fila* l, void** itemPtr);
bool ultimo_Fila(Fila* f, void**itemPtr);
Fila* destroi_Fila(Fila* f);

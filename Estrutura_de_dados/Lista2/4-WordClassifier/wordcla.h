
typedef struct node Fila_node;
typedef struct fila Fila;

Fila* cria_Fila(char *inicial);

bool enfilera_Fila(Fila* queue, void**itemPtr);
bool desenfilera_Fila(Fila* queue, void**itemPtr);
bool primeiro_Fila(Fila* queue, void** itemPtr);
bool ultimo_Fila(Fila* queue, void**itemPtr);
bool Fila_vazia(Fila* queue);
bool Fila_cheia(Fila* queue);
int tamanho_Fila(Fila* queue);
Fila* destroi_Fila(Fila* queue);
void mostra_Fila(Fila *queue);
int encontrar_Indice(char *letra);

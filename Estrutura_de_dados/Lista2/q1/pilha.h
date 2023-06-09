#ifndef PILHA_H
#define PILHA_H



#define max_elementos 10
/// @brief 
typedef struct
{
    int elementos[max_elementos];
    int topo;
}Pilha;



void criar_pilha(Pilha* p);
void empilhar(Pilha* p, int element);
void desempilhar(Pilha* p);
int topo(Pilha p);
int tamanho(Pilha p);
int vazia(Pilha p);



#endif
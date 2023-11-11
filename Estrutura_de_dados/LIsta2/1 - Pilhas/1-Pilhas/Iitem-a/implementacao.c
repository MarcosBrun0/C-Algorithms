#include "pilha.h"
#include <stdlib.h>
#include <stdio.h>

void criar_pilha(Pilha* p){
    p->topo = -1;

}

void empilhar(Pilha* p, int element){
    if (p->topo <max_elementos){

    
    p->topo++;
    p->elementos[p->topo]= element;
    }
    else{
        printf("A Pilha está cheia!");
    }
}

void desempilhar(Pilha*p){
        p->elementos[p->topo]=0;
        p->topo--;

}

int topo(Pilha p){
    return p.elementos[p.topo];

}

int vazia(Pilha p){
    if(p.topo < 0){
        return 1;
    }
}
    

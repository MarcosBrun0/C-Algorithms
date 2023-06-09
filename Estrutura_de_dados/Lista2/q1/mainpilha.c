#include <stdlib.h>
#include "pilha.h"
#include "implementacao.c"



int main(void){
    int top;

    Pilha minha_pilha;
    criar_pilha(&minha_pilha);
    empilhar(&minha_pilha,1);
    empilhar(&minha_pilha, 2);
    empilhar(&minha_pilha, 10);
    desempilhar(&minha_pilha);
    top = topo(minha_pilha);
    printf("o topo da pilha é %d", top);
}       


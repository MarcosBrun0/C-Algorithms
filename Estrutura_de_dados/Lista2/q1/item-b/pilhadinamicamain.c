#include <stdlib.h>
#include <stdio.h>
#include "pilhadinamica.h"
#include "pilhadinamica.c"

int main(void){

    Pilha* pilha;



    pilha = criarPilha();
    empilhar(pilha, 10);
    empilhar(pilha, 20);
    topo(pilha);
    








}
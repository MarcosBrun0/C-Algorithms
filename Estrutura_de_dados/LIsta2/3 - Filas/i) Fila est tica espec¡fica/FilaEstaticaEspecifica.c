#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "FilaEstaticaEspecifica.h"

struct fila {
    int v[TAMANHO];                   	 				//tamanho fila
    int primeiro, contador, ultimo;						//primeiro elemento, numero de elementos, aponta o proximo posição disponivel
};	

Fila* cria_Fila() {										//cria a fila
    Fila* f;											//cria o ponteiro fila
    f = (Fila*)malloc(sizeof(Fila));					//aloca memoria para o ponteiro
    
	if(f != NULL) {
        (f->primeiro) = 0;								//caso não exista inicializa cada um
        (f->ultimo) = 0;	
        (f->contador) = 0;
    }
    return f;											//retorna fila criada
}

int Fila_vazia(Fila* f) {								//verifica fila vazia
    if(f != NULL){										//verifica se contador igual a 0
    	return (f->contador) == 0;
	}
    printf("ERRO: Fila nao existe");					//fila não existe
    exit(-1);
}

int Fila_cheia(Fila* f) {								//verifica fila cheia
    if(f != NULL) {
    	return ((f->contador) == TAMANHO);  			//verifica se contador igual ao tamanho
	}
    printf("ERRO: Fila nao existe");					//fila não existe
    exit(-1);
}

int enfilera_Fila(Fila* f, int data) {					//insere elemento no final da fila
    if(f && f->contador != TAMANHO) {					//verifica se o ponteiro e o contador são diferentes do tamanho da fila
        f->v[f->ultimo] = data;							//dados é passado para o ultimo da fila
        printf("\n%d entrou na fila", f->v[f->ultimo]); // mostra que elemento foi adicionado a fila
        f->ultimo = (f->ultimo + 1)%TAMANHO;			// valor do ultimo é atualizado dentro da fila
        (f->contador)++;								// incrementa contador
        return 1;
    }
    else{
        printf("ERRO: A fila esta fora de alcance ou não existe");		//fila não existe
        exit(-1);
    }
}

int desenfilera_Fila(Fila* f) {							//desenfilera fila
    if (!Fila_vazia(f)) {								//se diferente de vazia
    	int n;									
		printf("\n%d saiu da fila",f->v[f->primeiro]);  // mostra elemento que saiu da fila
    	n = f->v[f->primeiro];							// n recebe valor do primeiro elemento
        f->primeiro = (f->primeiro + 1)%TAMANHO;		// indice primerio atualizado para apontar pro próximo elemento
        (f->contador)--;								// atualiza contador
        
        return n;										//retorna valor removido
    }	
    else {
        printf("ERRO: Fila esta vazia!\n");				//erro
        exit(-1);
    }
}

int tamanho_Fila(Fila* f) {
    if(f != NULL){
    	return (f->contador);			//retorn numero de elementos
	}
    return -1;
}

int primeiro_Fila(Fila* f) {			//mostra primeiro da fila sem retira-lo
    int dataOut;					
    if(!Fila_vazia(f)) {
        dataOut = f->v[f->primeiro];	//recebe valor do primeiro
        return dataOut;				    //retorna o primeiro
    }
    printf("ERRO: Fila esta vazia");	//fila vazia
    exit(-1);
}

void destroi_Fila(Fila* f) {			//libera memória
    free(f);
}

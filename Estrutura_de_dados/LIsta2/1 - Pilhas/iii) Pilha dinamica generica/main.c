#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "PilhaDinamicaGenerica.h"

int main () {
	Pilha* p;
	float* data;					//armazena dados inserido pelo usuário
	bool done = 0;				//verifica se ocorreu a entrada de dados
	
	p = cria_Pilha();
	
	printf("Digite um valor (Para parar digite -1) \n");
	while (!done){									//enquanto ocorrer a entrada de dados
		data = (float*)malloc(sizeof(float));			//aloca memória pra o ponteiro que armazena dados
		scanf("%f", data);			
		if((Pilha_cheia(p)) || (*data == -1)) {		//se a pilha estiver cheio ou atender a condição de parada digitada pelo usuário
			done = 1;								//para o while pq atribui 1 ao done, logo ele fica verdadeiro
		}else{
			insere_Pilha(p, data);					//insere os dados na pilha
		}
	}
	
	printf("\n");
	
	while (!Pilha_vazia(p)) {								//enquanto não estiver vazia
		data = (float*)remove_Pilha(p);						//data recebe dado do elemento removido da pilha
		printf("Elemento removido da pilha: %f\n", *data);  //imprime o conteúdo do ponteirio data, que é o item removido da pilha
		free(data);
	}	
}

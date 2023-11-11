#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "PilhaDinamicaEspecifica.h" 

int main () {	
	Pilha* p;						
	int *data;						//armazena dados inserido pelo usu�rio
	int done;						//verifica se ocorreu a entrada de dados
	
	p = cria_Pilha();
	
	printf("Digite um valor inteiro (Para parar digite -1) \n");
	while (!done){										//enquanto ocorrer a entrada de dados 
		data = (int*)malloc(sizeof(int));				//aloca mem�ria pra o ponteiro que armazena dados
		scanf("%d", data);
		if((Pilha_cheia(p)) || (*data == -1)) {			//se a pilha estiver cheio ou atender a condi��o de parada digitada pelo usu�rio
			done = 1;									//para o while pq atribui 1 ao done, logo ele fica verdadeiro
		}else{
			insere_Pilha(p, data);						//insere os dados na pilha
		}
	}
	
	printf("\n");
	
	while (!Pilha_vazia(p)) {								//enquanto n�o estiver vazia
		data = remove_Pilha(p);								//data recebe dado do elemento removido da pilha
		printf("Elemento removido da pilha: %d\n", *data);	//imprime o conte�do do ponteirio data, que � o item removido da pilha
		free(data);
	}
	return 0;
}


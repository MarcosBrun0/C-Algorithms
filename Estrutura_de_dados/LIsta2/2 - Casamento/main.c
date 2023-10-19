#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Casamento.h"

int main() {
    Pilha* p;																//ponteiro para pilha
    char token;																//caracteres lidos dos arquivos
    char *dataPtr;															//ponteiro para caractere
    char *getValue;															//ponteiro pro caractere do topo da pilha
    char fileID[25];														//vetor para id do arquivo
	int error,aberto = 0;													//error para erros, aberto para simbolos não correspondidos
    FILE* fpIn;																//ponteiro pro arquivo a ser lido
    int lineCount = 1, i = 0;    											//contador de linhas
    
	p = cria_Pilha();														//cria a pilha
    
    printf("Digite o ID do arquivo para o arquivo a ser analisado: ");		//nome do arquivo
    scanf("%s", fileID);

    fpIn = fopen(fileID, "r");												//abre o arquivo, pede o nome do arquivo e le o arquivo
    if(!fpIn) {	
       printf("Não é possível encontrar o %s", fileID);
       exit(-1);															//se ocorrer erro fecha o arquivo
    }

    getValue = (char*)malloc(sizeof(char));									//aloca memória pro ponteiro getValue

while((token = fgetc(fpIn)) != EOF) {										//le caractere por caractere até acabar o arquivo
	if (token == '\n'){														//se for \n incrementa o número de linhas
		lineCount++;
	}
       
	if(token == '(' || token == '[' || token == '{') {						//se o caractere for um de abertura
        dataPtr = (char*)malloc(sizeof(char));								//aloca memória para o ponteiro 
        *dataPtr = token;													//ponteiro armazena o valor do caractere lido
        insere_Pilha(p, dataPtr);											//insere o simbolo na pilha
        aberto++;															//simbolo de abertura
    } else if (token == ')' || token == ']' || token == '}') {				//por outro lado se o caractere for um de fechamento
        if (Pilha_vazia(p)) {												//verifica pilha vazia
            error = 1;
            printf("Erro: simbolo de fechamento sem correspondente na linha %d\n", lineCount);  //se vazia não existe caractere de abertura sem correspondente    
        } else {																				//mostra a linha em que se encontra o erro
            getValue = (char*)topo_Pilha(p);								//se não estiver vazia getValue recebe o topo da pilha
            if ((token == ')' && *getValue != '(') ||						
                (token == ']' && *getValue != '[') ||
                (token == '}' && *getValue != '{')) {						//se não forem correspondentes da erro
                error = 1;
                printf("Erro: simbolo de fechamento incorreto na linha %d\n", lineCount);	//mostra a linha em que se encontra o erro
            }else{
            	remove_Pilha(p);											//se houver correspondencia remove variavel aberta
            	aberto--;													//decrementa elementos sem correspondencia
			}
        }
    }
}

    if (!error) {																			
        if (!Pilha_vazia(p)) {																//se diferente de vazia faça
            printf("Erro: simbolo de abertura sem correspondente na linha %d\n", aberto);	//abertura sem correspondente
        } else {		
            printf("Casamento perfeito\n");													//se estiver vazia houve todos os casamentos
        }
    }
    
	printf("Tem %d elementos errados\n", tamanho_Pilha(p));									//quantidade de elementos errados
	
    fclose(fpIn);																			//fecha o arquivo
    destroi_Pilha(p);																		//distroi a pilha
    free(getValue);																			//limpou memória reservada para getValue

    return 0;
}

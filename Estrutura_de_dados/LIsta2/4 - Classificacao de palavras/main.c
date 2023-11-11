#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ClassificacaodePalavras.h"
#include <string.h>
#define MAX 30

int main() {
    char linha[500];											//armazena a quantidade de caracteres em uma linha
    char fileID[500];											//armazena o id do arquivo
    char *primeiraLetra;										//ponteiro para caractere pra criar filas
    char *data;													//ponteiro para armazenar palavaras lida no arquivo
    int f_index, i;												//armazenar os indices da fila de acordo com a primeira letra
    FILE* fpIn;													//ponteiro para o arquivo de entrada
    Fila *f[MAX];												//vetor de ponteiros para as filas

	
    printf("Digite o ID do arquivo: ");							//pede o usuário id do arquivo
    scanf("%s", fileID);										//le id do arquivo e armazena em fileId

    fpIn = fopen(fileID, "r");									//abre o arquivo no modo leitura
    if(!fpIn) {													
       printf("Arquivo nao encontrado %s", fileID);				//verificar se a abertura do arquivo deu certo
       exit(-1);												
    }

   for(i=0; i < MAX; i++) {										//criar fila para cada letra do alfabeto
        primeiraLetra = i + 'a';								//primeira letra é atualizada a cada iteração
        f[i] = cria_Fila(&primeiraLetra);						//cria a fila e armazena no f
   }

    while (fgets(linha, sizeof(linha), fpIn) != NULL) {			//ler cada linha do arquivo
        char* getWord = strtok(linha, " ");						//strtok obtem a primeira palavra de cada linha e guarda em getWord

        while (getWord != NULL) {								//executa enquanto tiver palavra	
			f_index = encontrar_Indice(&getWord[0]);			//ponteiro para o primeiro caractere da palavra e é armazenado no f_index

            if(f_index != -1){									
                enfilera_Fila(f[f_index], &getWord);			//coloca a palavra na sua fila correspondente (f_index mostra a fila correta e getword a palavra a ser adicionada)
            }
            getWord = strtok(NULL, " ");						//próxima palavra da linha
        }
    }

    fclose(fpIn);												//fecha arquivo

    for(i=0; i<MAX; i++) {										//mostra todas as filas de cada letra do alfabeto
        printf("%C: ", i + 'a');
        mostra_Fila(f[i]);
    }
}

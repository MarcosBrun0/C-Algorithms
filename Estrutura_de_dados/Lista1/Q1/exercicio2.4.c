//programa_memoria_02.c
#include <stdio.h>
#include <stdlib.h>


int main(void) {
  //A declaração de uma matriz de 2 dimensões exige um ponteiro para ponteiro.
  int ** p;
  int linhas, colunas;
  printf("\nDigite as dimensoes da matriz ->");
  scanf("%d %d", &linhas, &colunas);

  /* 
  Alocação da primeira dimensão. Internamente, a função calloc fará uma multiplicação da
  quantidade de elementos pelo tamanho de cada elemento para saber quanto de memória
  deve ser alocada. 
  */

  // Aloca as linhas da matriz
  p = calloc(linhas, sizeof(int));
  if (p == NULL) {
    printf("\nErro de alocacao de memoria");
    exit(1);
  }

  // Aloca as colunas da matriz
  for (int iterator = 0; iterator < linhas; iterator++) {
    //Alocação das linhas de cada coluna (segunda dimensão)
    p[iterator] = calloc(colunas, sizeof(int));
    if (p[iterator] == NULL) {
      printf("\nErro de alocacao de memoria");
      exit(1);
    }
  }

  // Insere o número na matriz
  for (int iterator = 0; iterator < linhas; iterator++) {
    for (int inner_iterator = 0; inner_iterator < colunas; inner_iterator++) {
      printf("Digite o numero para o indice %d,%d ->", iterator, inner_iterator);
      scanf("%d", & p[iterator][inner_iterator]);
    }
  }

  // Escreve a matriz no Console
  for (int iterator = 0; iterator < linhas; iterator++) {
    for (int inner_iterator = 0; inner_iterator < colunas; inner_iterator++) {
      printf("O numero do indice %d,%d eh %d\n", iterator, inner_iterator, p[iterator][inner_iterator]);
    }
      printf("\n");
  }

  printf("\nLiberando memoria alocada");
  for (int iterator = 0; iterator < linhas; iterator++) {
    free(p[iterator]); //Primeiro deve ser liberada a memória para linha da matriz...
  }
  free(p);
}

// Assinado, Sophia :P
// Tava sem nada pra fazer na 121 passando pelo código dos outro decidi mexer :P
// SIM, eu fiz no perfil de Emanuel

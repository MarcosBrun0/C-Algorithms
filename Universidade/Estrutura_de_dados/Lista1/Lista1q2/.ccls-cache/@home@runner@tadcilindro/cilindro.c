#include "cilindro.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

const float PI = 3.1415;
struct cilindro {
  float pos;
  float raio;
  float altura;
};

Cilindro *cria_cilindro(float pos, float raio, float altura) {

  Cilindro *c = (Cilindro *)malloc(sizeof(Cilindro));
  if (c == NULL) {
    printf("Erro na alocação");
  }
  c->pos = pos;
  c->raio = raio;
  c->altura = altura;
  return c;
}

float Area(Cilindro *c) { return PI * c->raio; }

float vol(Cilindro *c) { return PI * c->raio * c->raio * c->altura; }

float modcilin(Cilindro *c) {
  printf("Qual a altura do Cilindro?\n");
  scanf("%f", &c->altura);

  printf("Qual é o raio do Cilindro?\n");
  scanf("%f", &c->raio);

  printf("Qual é a posição do Cilindro?\n");
  scanf("%f", &c->pos);
  printf("Cilindro modificado com sucesso.\n");
}

void limpar(Cilindro *c) { free(c); }

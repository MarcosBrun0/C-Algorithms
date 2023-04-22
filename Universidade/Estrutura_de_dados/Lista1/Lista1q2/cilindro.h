#include <stdlib.h>

// posição, altura e raio

typedef struct cilindro Cilindro;

Cilindro *cria_cilindro(float pos, float raio, float altura);

float modcilin(Cilindro *c);

float vol(Cilindro *c);

float Area(Cilindro *c);

void limpar(Cilindro *c);
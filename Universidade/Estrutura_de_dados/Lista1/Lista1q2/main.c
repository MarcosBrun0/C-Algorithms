#include "cilindro.h"
#include <stdbool.h>
#include <stdio.h>

int main(void) {
  int count = 0;
  bool script_is_on = true;
  int options;
  Cilindro *c;
  Cilindro *c2;
  Cilindro *temp;
  float area;
  float volume;

  printf(" 1 para criar cilindro ; \n 2 para area;\n 3 para volume;\n "
         "4 para "
         "modificar cilindro;\n 5 para apagar cilindro;\n 6 para encerrar "
         "programa;\n 7 para mudar de espaço.\n");

  while (script_is_on) {
    scanf("%d", &options);

    switch (options) {
    case 1:
      if (count % 2 == 0) {
        c = cria_cilindro(10, 2, 5);
        temp = c;
        printf("Cilindro A criado.\n");

      } else {
        c2 = cria_cilindro(10, 3, 8);
        temp = c2;
        printf("Cilindro B criado.\n");
      }
      break;
    case 2:
      area = Area(temp);
      printf("area: %f \n", area);
      break;
    case 3:
      volume = vol(temp);
      printf("volume: %f \n", volume);
      break;
    case 4:
      modcilin(temp);
      break;
    case 5:
      limpar(temp);
      printf("Apagado.\n");
      break;
    case 6:
      script_is_on = false;
      exit(1);
    case 7:
      if (count % 2 == 0) {
        c = temp;
        temp = c2;
        printf("Espaço B selecionado.\n");
      } else {
        c2 = temp;
        temp = c;
        printf("Espaço A selecionado.\n");
      }
      count++;

      break;
    }
  }
}

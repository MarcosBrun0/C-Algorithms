#include <stdio.h>
#include <stdlib.h>
#include "ArvoreAVL.h" // Inclui prot�tipos

// A estrutura do n� da �rvore, possui 3 campos: informa��o inteira, ponteiro esquerdo e ponteiro direito.
struct NO{
   int info;
   int alt;
   struct NO* esq;
   struct NO* dir;
};

// Cria uma �rvore bin�ria nula,
// que � um ponteiro duplo nulo a um n�.
ArvAVL* cria_ArvAVL(){
   // aloca mem�ria para um ponteiro a um n�, e retorna o endere�o desse ponteiro
   ArvAVL* raiz = (ArvAVL*) malloc(sizeof(ArvAVL));
   if (raiz != NULL)
      *raiz = NULL;
   return raiz;
};

// fun��o recursiva que libera a mem�ria alocada
// a cada n� de uma sub�rvore
void libera_NO(struct NO* no){
  // condi��o de parada
   if (no == NULL)
      return
  // inicio das recorr�ncias
   libera_NO(no->esq);
   libera_NO(no->dir);
  // fim das recorr�ncias
  free(no);  /* libera a memoria alocada ao n� */
  no = NULL; /* faz o ponteiro nulo */
}

// fun��o que libera a mem�ria alocada a todos os n�s da �rvore;
// para isso usa a fun��o recursiva libera_NO().
void libera_ArvAVL(ArvAVL* raiz){
   // caso trivial ou nulo
   if (raiz == NULL) /* caso a �rvore n�o tenha sido criada */
      return;
   // chamada a fun��o recursiva
   libera_NO(*raiz); /* libera cada n� */
   // libera a raiz
   free(raiz);
};

// fun��o recursiva que retorna a altura da �rvore
int altura_ArvAVL(ArvAVL* raiz){
   // condi��o de parada
   if (raiz == NULL)
      return 0;
   if (*raiz == NULL)
      return 0;
   // inicio da recorr�ncia
   // calcula a altura esquerda e a altura direita
   int alt_esq = altura_ArvAVL(&((*raiz)->esq));
   int alt_dir = altura_ArvAVL(&((*raiz)->dir));
   // fim da recorrencia
   // calculo da altura da sub�rvore
   if (alt_esq >alt_dir)
      return (alt_esq + 1);
   else
      return (alt_dir + 1);
};

//retorna a altura de um n�
int alt_NO(struct NO* no){
   if (no == NULL)
       return 0;  /* 0 � um valor nulo */
   else
      return no->alt;
}

// retorna o fator de balanceamento de um n�
int fatorBalanceamento_NO(struct NO* no){
   return labs(alt_NO(no->esq)-alt_NO(no->dir));
}

// retorna o maior entre dois valores
int maior (int x, int y){
   if (x > y)
      return x;
   else
      return y;
}

// fun��o recursiva que calcula o n�mero de n�s da �rvore
int totalNO_ArvAVL(ArvAVL* raiz){
   // condi��o de parada
   if (raiz == NULL)
      return 0;
   if (*raiz == NULL)
      return 0;
   // inicio da recorr�ncia
   // calcula o total de n�s a esquerda e a direita
   int total_esq = totalNO_ArvAVL(&((*raiz)->esq));
   int total_dir = totalNO_ArvAVL(&((*raiz)->dir));
   // fim da recorrencia
   // calculo do total de n�s da sub�rvore
   return (total_esq + total_dir + 1);
};

// rota��o LL: rota��o do caso Esquerda-Esquerda
// rota��o simples � direita
// A: ponteiro duplo, primeiro n� desbalanceado
// B: ponteiro simples, filho esquerdo de A
void RotacaoLL (ArvAVL *A) {
   struct NO *B;
   B = (*A)->esq;
   // reconex�es correpondentes � rora��o � direita
   (*A)->esq = B->dir;
   B->dir = *A;
   // recalculo das alturas: (*A) abaixo de B
   (*A)->alt = maior(alt_NO((*A)->esq),
                     alt_NO((*A)->dir))+1;
   B->alt = maior(alt_NO(B->esq),(*A)->alt)+1;
   // atualiza��o do ponteiro de cima
   *A = B;
}

// rota��o RR: rota��o do caso Direita-Direita
// rota��o simples � esquerda
// A: ponteiro duplo, primeiro n� desbalanceado
// B: ponteiro simples, filho direito de A
void RotacaoRR (ArvAVL *A) {
   struct NO *B;
   B = (*A)->dir;
   // reconex�es correpondentes � rora��o � esquerda
   (*A)->dir = B->esq;
   B->esq = *A;
   // recalculo das alturas: (*A) abaixo de B
   (*A)->alt = maior(alt_NO((*A)->esq),
                     alt_NO((*A)->dir))+1;
   B->alt = maior(alt_NO(B->dir),(*A)->alt)+1;
   // atualiza��o do ponteiro de cima
   *A = B;
}

// rota��o LR: rota��o do caso Esquerda-Direita
// rota��o dupla � direita
// A: ponteiro duplo, primeiro n� desbalanceado
// B: ponteiro simples, filho esquerdo de A
void RotacaoLR (ArvAVL *A) {
    RotacaoRR(&(*A)->esq); /* Rota��o esquerda em B */
    RotacaoLL(A);          /* Rota��o direita em A */
}

// rota��o RL: rota��o do caso Direita-Esquerda
// rota��o dupla � esquerda
// A: ponteiro duplo, primeiro n� desbalanceado
// B: ponteiro simples, filho direito de A
void RotacaoRL (ArvAVL *A) {
    RotacaoLL(&(*A)->dir); /* Rota��o direita em B  */
    RotacaoRR(A);          /* Rota��o esquerda em A */
}

// fun��o recursiva que insere um novo n� na �rvore AVL
// de acordo com o valor fornecido.
// retorna 0 se a inser��o for invi�vel e 1 se for vi�vel.
// calcula o fator de balanceamento, e corrige a �rvore AVL
int insere_ArvAVL(ArvAVL* raiz, int valor){
   int res;
   // caso trivial ou nulo
   if (raiz == NULL)
      return 0;
   // Condi��o de parada: �rvore vazia ou folha
   if (*raiz == NULL){
     // cria��o do novo n�
   struct NO* novo;
   novo = (struct NO*) malloc(sizeof(struct NO));
   if (novo == NULL)
      return 0;
   novo->info = valor;
   novo->alt = 0;
   novo->dir = NULL;
   novo->esq = NULL;
   *raiz = novo;
   return 1;
   }
   // recorr�ncia
   struct NO* atual = *raiz;
   if (valor < atual->info){
      if ((res = insere_ArvAVL(&(atual->esq),valor)) == 1){
         if (fatorBalanceamento_NO(atual) >= 2){
            if (valor < (*raiz)->esq->info)
               RotacaoLL(raiz); /* caso esquerda-esquerda */
            else
               RotacaoLR(raiz); /* caso esquerda-direita */
         }
      }
   }else {
      if (valor > atual->info){
         if ((res = insere_ArvAVL(&(atual->dir),valor)) == 1){
            if (fatorBalanceamento_NO(atual) >= 2){
               if (valor > (*raiz)->dir->info)
                  RotacaoRR(raiz); /* caso direita-direita */
               else
                  RotacaoRL(raiz); /* caso direita-esquerda */
         }
      }
   }
   else /* valor duplicado */
   return 0;
   }
   atual->alt=maior(alt_NO(atual->esq),alt_NO(atual->dir))+1;
   return res;
};

// fun��o sequ�ncial que procura o menor n� da sub�rvore com raiz atual
struct NO* procuraMenor(struct NO* atual){
   struct NO *no1 = atual, *no2 = atual->esq;
   while (no2 != NULL){
      no1 = no2;
      no2 = no2->esq;
   }
   return no1;
}

// fun��o recursiva que remove um n� na �rvore AVL
// que corresponde ao valor indicado,
// retorna 0 se a remo��o for invi�vel e 1 se for vi�vel.
int remove_ArvAVL(ArvAVL* raiz, int valor){
   int res;
   // caso trivial ou nulo
   if (raiz == NULL)
      return 0;
   if (*raiz == NULL) /* valor n�o existe */
      return 0;
   // etapa de busca - recorr�ncia
   // struct NO* atual = *raiz;
   if (valor < (*raiz)->info){
      if ((res = remove_ArvAVL(&(*raiz)->esq,valor)) == 1){
         if (fatorBalanceamento_NO(*raiz) >= 2){
            if (alt_NO((*raiz)->dir->esq)<=
               alt_NO((*raiz)->dir->dir))
               RotacaoRR(raiz); /* caso direita-direita */
            else
               RotacaoRL(raiz); /* caso direita-esquerda */
         }
      }
   }
   if (valor > (*raiz)->info){
      if ((res = remove_ArvAVL(&(*raiz)->dir,valor)) == 1){
         if (fatorBalanceamento_NO(*raiz) >= 2){
            if (alt_NO((*raiz)->esq->dir)<=
               alt_NO((*raiz)->esq->esq))
               RotacaoLL(raiz); /* caso esquerda-esquerda */
            else
               RotacaoLR(raiz); /* caso esquerda-direita */
         }
      }
   }
   // Condi��o de parada
   if ((*raiz)->info == valor){ /* encontrou o elemento */
     // se a raiz tem apenas um filho ou nenhum
      if (((*raiz)->esq == NULL) || ((*raiz)->dir == NULL)){
         struct NO* no1 = (*raiz);
         if ((*raiz)->esq != NULL)
            *raiz = (*raiz)->esq; /* encadeia a sub�rvore esquerda */
         else
            *raiz = (*raiz)->dir; /* encadeia a sub�rvore direita */
         free(no1);
      }
      else { // a raiz tem dois filhos
         struct NO* no1 = procuraMenor((*raiz)->dir); /* procura o sucessor          */
         (*raiz)->info = no1->info;        /* substitui o valor da raiz   */
         remove_ArvAVL(&(*raiz)->dir, no1->info); /* remove o n� sucessor */
         if (fatorBalanceamento_NO(*raiz) >=2){
            if (alt_NO((*raiz)->esq->dir) <=
               alt_NO((*raiz)->esq->esq))
               RotacaoLL(raiz); /* caso esquerda-esquerda */
            else
               RotacaoLR(raiz); /* caso esquerda-direita */
         }
      }
     // recalcula a altura do n� raiz
      if (*raiz != NULL)
         (*raiz)->alt = maior(alt_NO((*raiz)->esq),
                           alt_NO((*raiz)->dir))+1;
      return 1;
   }
   // recalcula a altura do n� raiz
   (*raiz)->alt = maior(alt_NO((*raiz)->esq),
                        alt_NO((*raiz)->dir))+1;
   return res;                 /* retorna o resultado da remo��o */
};

// verifica se a �rvore est� vazia: 1(Sim) 0 (N�o)
// raiz � um ponteiro duplo ao n� raiz da �rvore
int estaVazia_ArvAVL(ArvAVL* raiz){
   if (raiz == NULL)  /* A �rvore n�o foi criada */
      return 1;
   if (*raiz == NULL) /* A �rvore foi criada, mas n�o cont�m elementos */
      return 1;
   return 0;          /* A �rvore possui elementos */
};



// fun��o sequencial que percorre a �rvore de busca bin�ria desde a raiz at�:
// achar o valor desejado 1 (sim) ou confirmar que o valor n�o existe 0 (n�o).
int consulta_ArvAVL(ArvAVL* raiz, int valor){
   // cpndi��o de parada
   if (raiz == NULL)
      return 0;
   // percurso sequ�ncial
   struct NO* atual = *raiz;   /* ponteiro ao n� raiz */
   while (atual != NULL){
      if (valor == atual->info){
         return 1;             /* valor encontrado */
      }
      if (valor > atual->info)
        atual = atual->dir;    /* desce pela sub�rvore direita */
      else
        atual =atual->esq;     /* desce pela sub�rvore esquerda */
   }
   return 0;                   /* valor n�o existe */
};

// fun��o recursiva que percorre a �rvore em-ordem imprimindo os dados.
void emOrdem_ArvAVL(ArvAVL* raiz){
    // condi��o de parada
   if (*raiz == NULL)
      return;
   // inicio da recorr�ncia
   if (*raiz != NULL) {
      emOrdem_ArvAVL(&((*raiz)->esq));
      printf("%d\n",(*raiz)->info);
      emOrdem_ArvAVL(&((*raiz)->dir));
   }
   // fim da recorr�ncia
};

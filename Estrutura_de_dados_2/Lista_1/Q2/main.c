
#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar um elemento na fila de prioridade
typedef struct
{
    int prioridade;
    int ordemChegada;
    // Outros campos de dados, se necessário
} Elemento;

// Estrutura para 5representar a fila de prioridade
typedef struct
{
    Elemento *array; // Array de elementos
    int tamanho;     // Número de elementos na fila de prioridade
    int capacidade;  // Capacidade máxima da fila de prioridade
} FilaDePrioridade;

// Função para criar uma nova fila de prioridade
FilaDePrioridade *criarFilaDePrioridade(int capacidade)
{
    FilaDePrioridade *fila = (FilaDePrioridade *)malloc(sizeof(FilaDePrioridade));
    fila->capacidade = capacidade;
    fila->tamanho = 0;
    fila->array = (Elemento *)malloc(capacidade * sizeof(Elemento));
    return fila;
}

// Função para trocar dois elementos
void trocar(Elemento *a, Elemento *b)
{
    Elemento temp = *a;
    *a = *b;
    *b = temp;
}

// Função para mover um elemento para cima na fila de prioridade
void subir(FilaDePrioridade *fila, int indice)
{
    int pai = (indice - 1) / 2;
    while (indice > 0 && fila->array[indice].prioridade > fila->array[pai].prioridade)
    {
        trocar(&fila->array[indice], &fila->array[pai]);
        indice = pai;
        pai = (indice - 1) / 2;
    }
}

// Função para inserir um elemento na fila de prioridade
void inserir(FilaDePrioridade *fila, int prioridade, int ordemChegada)
{
    if (fila->tamanho == fila->capacidade)
    {
        printf("A fila de prioridade está cheia.\n");
        return;
    }

    Elemento elemento;
    elemento.prioridade = prioridade;
    elemento.ordemChegada = ordemChegada;

    fila->array[fila->tamanho] = elemento;
    fila->tamanho++;

    subir(fila, fila->tamanho - 1);
}

// Função para mover um elemento para baixo na fila de prioridade
void descer(FilaDePrioridade *fila, int indice)
{
    int filhoEsq = 2 * indice + 1;
    int filhoDir = 2 * indice + 2;
    int maior = indice;

    if (filhoEsq < fila->tamanho && fila->array[filhoEsq].prioridade > fila->array[maior].prioridade)
    {
        maior = filhoEsq;
    }

    if (filhoDir < fila->tamanho && fila->array[filhoDir].prioridade > fila->array[maior].prioridade)
    {
        maior = filhoDir;
    }

    if (maior != indice)
    {
        trocar(&fila->array[indice], &fila->array[maior]);
        descer(fila, maior);
    }
}

// Função para remover e retornar o elemento de maior prioridade da fila de prioridade
Elemento removerMaximo(FilaDePrioridade *fila)
{
    if (fila->tamanho == 0)
    {
        printf("A fila de prioridade está vazia.\n");
        Elemento elementoVazio;
        elementoVazio.prioridade = 0;
        elementoVazio.ordemChegada = 0;
        return elementoVazio;
    }

    Elemento maximo = fila->array[0];
    fila->array[0] = fila->array[fila->tamanho - 1];
    fila->tamanho--;

    descer(fila, 0);

    return maximo;
}

// Função para liberar a memória alocada para a fila de prioridade
void liberarFilaDePrioridade(FilaDePrioridade *fila)
{
    free(fila->array);
    free(fila);
}

int main()
{
    FilaDePrioridade *fila = criarFilaDePrioridade(10);

    // Exemplo de inserção de elementos na fila de prioridade
    inserir(fila, 5, 1);
    inserir(fila, 3, 2);
    inserir(fila, 8, 3);
    inserir(fila, 1, 4);

    // Remover e imprimir os elementos em ordem de prioridade
    while (fila->tamanho > 0)
    {
        Elemento elemento = removerMaximo(fila);
        printf("Prioridade: %d, Ordem de Chegada: %d\n", elemento.prioridade, elemento.ordemChegada);
    }

    liberarFilaDePrioridade(fila);

    return 0;
}
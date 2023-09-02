cmake_minimum_required(VERSION 3.26)
project(Computer_Science_UENF C)

set(CMAKE_C_STANDARD 11)

include_directories(Estrutura_de_dados/Lista1)
include_directories(Estrutura_de_dados/LIsta2/1-Pilhas/Iitem-a)
include_directories(Estrutura_de_dados/LIsta2/1-Pilhas/item-b)
include_directories(Estrutura_de_dados/LIsta2/4-WordClassifier)

add_executable(Computer_Science_UENF
        Estrutura_de_dados/Lista1/Lista1q1/exercicio2.4.c
        Estrutura_de_dados/Lista1/Lista1q1/exercicio2.5.c
        Estrutura_de_dados/Lista1/Lista1q1/exercicio2.7.c
        Estrutura_de_dados/Lista1/Lista1q1/exercicio2.8.c
        Estrutura_de_dados/Lista1/Lista1q3/TAD-ordenacao/main.c
        Estrutura_de_dados/Lista1/Lista1q3/TAD-ordenacao/tadord.c
        Estrutura_de_dados/Lista1/Lista1q3/Bubllesort.c
        Estrutura_de_dados/Lista1/Lista1q3/Inserctionsort.c
        Estrutura_de_dados/Lista1/Lista1q3/Selectionsort.c
        Estrutura_de_dados/Lista1/cilindro.c
        Estrutura_de_dados/Lista1/cilindro.h
        Estrutura_de_dados/Lista1/main.c
        Estrutura_de_dados/LIsta2/1-Pilhas/Iitem-a/implementacao.c
        Estrutura_de_dados/LIsta2/1-Pilhas/Iitem-a/mainpilha.c
        Estrutura_de_dados/LIsta2/1-Pilhas/Iitem-a/pilha.h
        Estrutura_de_dados/LIsta2/1-Pilhas/item-b/pilhadinamica.c
        Estrutura_de_dados/LIsta2/1-Pilhas/item-b/pilhadinamica.h
        Estrutura_de_dados/LIsta2/1-Pilhas/item-b/pilhadinamicamain.c
        Estrutura_de_dados/LIsta2/4-WordClassifier/mainwordcla.c
        Estrutura_de_dados/LIsta2/4-WordClassifier/wordcla.c
        Estrutura_de_dados/LIsta2/4-WordClassifier/wordcla.h
        Estrutura_de_dados_2/Lista_1/MergeSort.c)

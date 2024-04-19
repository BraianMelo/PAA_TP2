#ifndef SEQUENCIA_H

    #define SEQUENCIA_H

    #include <stdio.h>
    #include <malloc.h>
    #include <stdbool.h>

    #define ESQUERDA posicao-1
    #define DIREITA posicao+1

    typedef struct Sequencia{
        int tamanho_max;
        int qtd_numeros;
        int *numeros;
    } Sequencia;

    Sequencia *criar_Sequencia();
    bool iniciar_Sequencia(Sequencia *sequencia, int tamanho_max);
    bool adicionar_numero_Sequencia(Sequencia *sequencia, int numero);
    bool remover_conjunto_Sequencia(Sequencia *sequencia, int posicao);
    bool remover_numero_Sequencia(Sequencia *sequencia, int posicao);
    bool sequencia_estah_vazia(Sequencia *sequencia);
    bool imprimir_Sequencia(Sequencia *sequencia);
    bool desalocar_Sequencia(Sequencia *sequencia);

#endif
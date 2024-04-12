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
        bool *valor_removido;
    } Sequencia;

    Sequencia *criar_Sequencia();
    bool iniciar_Sequencia(Sequencia *sequencia, int tamanho_max);
    bool adicionar_numero_Sequencia(Sequencia *sequencia, int numero);
    bool remover_numero_Sequencia(Sequencia *sequencia, int posicao);
    bool imprimir_Sequencia(Sequencia *sequencia);
    bool desalocar_Sequencia(Sequencia *sequencia);

#endif
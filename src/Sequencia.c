#include "../include/Sequencia.h"

Sequencia *criar_Sequencia(){
    Sequencia *sequencia = (Sequencia*) malloc(sizeof(Sequencia));
    sequencia->numeros = NULL;
    sequencia->valor_removido = NULL;
    return sequencia;
}

bool iniciar_Sequencia(Sequencia *sequencia, int tamanho_max){
    if(sequencia->numeros !=NULL)
        return false;

    sequencia->tamanho_max =  tamanho_max;
    sequencia->qtd_numeros = 0;

    sequencia->valor_removido = (bool*) malloc(sizeof(bool) * tamanho_max);
    sequencia->numeros = (int*) malloc(sizeof(int) * tamanho_max);

    return true;
}

bool adicionar_numero_Sequencia(Sequencia *sequencia, int numero){
    if(sequencia->numeros == NULL || sequencia->qtd_numeros == sequencia->tamanho_max)
        return false;

    sequencia->numeros[sequencia->qtd_numeros] = numero;
    sequencia->valor_removido[sequencia->qtd_numeros++] = false;
    return true;
}

bool remover_numero_Sequencia(Sequencia *sequencia, int posicao){
    if(sequencia->numeros == NULL || posicao >= sequencia->tamanho_max)
        return false;

    if(ESQUERDA >= 0)
        sequencia->valor_removido[ESQUERDA] = true;

    sequencia->valor_removido[posicao] = true;

     if(DIREITA < sequencia->tamanho_max)
        sequencia->valor_removido[DIREITA] = true;

    return true;    
}

bool imprimir_Sequencia(Sequencia *sequencia){
    if(sequencia->numeros == NULL)
        return false;

    for(int i = 0; i < sequencia->qtd_numeros; ++i){
        if(!sequencia->valor_removido[i])
            printf("%d ", sequencia->numeros[i]);
    }
    printf("\n");
    return true;
}

bool desalocar_Sequencia(Sequencia *sequencia){
    free(sequencia->numeros);
    free(sequencia->valor_removido);
    free(sequencia);
    return true;
}
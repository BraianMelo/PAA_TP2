#include "../include/Sequencia.h"

Sequencia *criar_Sequencia(){
    Sequencia *sequencia = (Sequencia*) malloc(sizeof(Sequencia));
    sequencia->numeros = NULL;
    return sequencia;
}

bool iniciar_Sequencia(Sequencia *sequencia, int tamanho_max){
    if(sequencia->numeros !=NULL)
        return false;

    sequencia->tamanho_max =  tamanho_max;
    sequencia->qtd_numeros = 0;

    sequencia->numeros = (int*) malloc(sizeof(int) * tamanho_max);

    return true;
}

bool adicionar_numero_Sequencia(Sequencia *sequencia, int numero){
    if(sequencia->numeros == NULL || sequencia->qtd_numeros == sequencia->tamanho_max)
        return false;

    sequencia->numeros[sequencia->qtd_numeros++] = numero;
    return true;
}

bool remover_conjunto_Sequencia(Sequencia *sequencia, int posicao){
    if(sequencia->numeros == NULL || posicao >= sequencia->tamanho_max)
        return false;

    if(ESQUERDA >= 0)
        remover_numero_Sequencia(sequencia, --posicao);

    remover_numero_Sequencia(sequencia, posicao);

    if(DIREITA < sequencia->tamanho_max)
        remover_numero_Sequencia(sequencia, posicao);

    return true;    
}

bool remover_numero_Sequencia(Sequencia *sequencia, int posicao) {
    if (sequencia == NULL || sequencia->numeros == NULL || posicao < 0 || posicao >= sequencia->qtd_numeros)
        return false;

    for (int i = posicao; i < sequencia->qtd_numeros - 1; ++i) {
        sequencia->numeros[i] = sequencia->numeros[i + 1];
    }

    sequencia->qtd_numeros--;

    return true;
}

bool sequencia_estah_vazia(Sequencia *sequencia){
    if(sequencia->numeros == NULL || sequencia->qtd_numeros == 0)
        return true;

    return false;
}

bool imprimir_Sequencia(Sequencia *sequencia){
    if(sequencia->numeros == NULL)
        return false;

    for(int i = 0; i < sequencia->qtd_numeros; ++i){
            printf("%d ", sequencia->numeros[i]);
    }
    printf("\n");
    return true;
}

bool desalocar_Sequencia(Sequencia *sequencia){
    free(sequencia->numeros);
    free(sequencia);
    return true;
}
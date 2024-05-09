#include "../include/Alternativa.h"

int chamada_recursiva(Sequencia *sequencia, int tamanho){
  if(sequencia->qtd_numeros == 0)
        return 0;

    if(sequencia->qtd_numeros == 1){
        return sequencia->numeros[0];
    }

    if(sequencia->qtd_numeros == 2){
        return maior(sequencia->numeros[0], sequencia->numeros[1]);

    long int incluso = sequencia->numeros[sequencia->qtd_numeros - 1] + chamada_recursiva(sequencia, tamanho - 2);
    long int excluso = chamada_recursiva(sequencia, tamanho - 1);

    return maior(incluso, excluso);

    }
}

bool metodo_Alternativo(Sequencia *sequencia){
    int pontuacao = chamada_recursiva(sequencia, sequencia->qtd_numeros);
    printf("%d \n", pontuacao);
    return true;
}


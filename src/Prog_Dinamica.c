#include "../include/Prog_Dinamica.h"

int maior(unsigned a, unsigned b){
    return (a > b) ? a : b;
}

bool metodo_Dinamico(Sequencia *sequencia) {
    if(sequencia->qtd_numeros == 0)
        return false;

    if(sequencia->qtd_numeros == 1){
        printf("%d\n", sequencia->numeros[0]);
        return true;
    }

    if(sequencia->qtd_numeros == 2){
        printf("%d\n", maior(sequencia->numeros[0], sequencia->numeros[1]));
        return true;
    }

    int incluso = sequencia->numeros[1];
    int excluso = sequencia->numeros[0];
    int var_temporaria;

    for (int i = 2; i < sequencia->qtd_numeros; i++) {
        var_temporaria = incluso;
        incluso = excluso + sequencia->numeros[i];
        excluso = maior(excluso, var_temporaria);

    }

    int pontuacao = maior(incluso, excluso);
    printf("%d\n", pontuacao);
}
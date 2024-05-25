#include "../include/Alternativa.h"

bool metodo_Alternativo(Sequencia *sequencia, FILE **arquivo_saida){

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

    Sequencia *pontuacao = criar_Sequencia();
    iniciar_Sequencia(pontuacao, sequencia->tamanho_max);

    adicionar_numero_Sequencia(pontuacao, sequencia->numeros[0]);
    adicionar_numero_Sequencia(pontuacao, sequencia->numeros[1]);
    adicionar_numero_Sequencia(pontuacao, sequencia->numeros[2] + sequencia->numeros[0]);

    int maior_precedente;

    for(int i = 3; i < sequencia->tamanho_max; ++i){
        maior_precedente = maior(pontuacao->numeros[i-2], pontuacao->numeros[i-3]);
        adicionar_numero_Sequencia(pontuacao, sequencia->numeros[i] + maior_precedente);
    }

    int maior_valor = maior(pontuacao->numeros[pontuacao->qtd_numeros - 1], pontuacao->numeros[pontuacao->qtd_numeros - 2]);
    fprintf(*arquivo_saida, "%d \n", maior_valor);
    printf("%d \n", maior_valor);
    
    desalocar_Sequencia(pontuacao);

    return true;
}

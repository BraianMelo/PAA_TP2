#include "../include/Prog_Dinamica.h"

bool Dinamica(Sequencia *sequencia, int tamanho){

    int saldo, maior_saldo, posicao_maior_saldo, tamanho_anterior;
    long int pontuacao = 0;

    Sequencia *saldos = criar_Sequencia();
	iniciar_Sequencia(saldos, tamanho);

    for(int i = 0; i < sequencia->qtd_numeros; ++i){
        calcular_saldo(sequencia, i, &saldo);
        adicionar_numero_Sequencia(saldos, saldo);
    }

    while(!sequencia_estah_vazia(sequencia)){
        maior_saldo = saldos->numeros[0];
        posicao_maior_saldo = 0;

        for(int i = 1; i < sequencia->qtd_numeros; ++i){
            if(saldos->numeros[i] > maior_saldo){
                maior_saldo = saldos->numeros[i];
                posicao_maior_saldo = i;
            }
        }

        tamanho_anterior = sequencia->qtd_numeros - 1;

        pontuacao += sequencia->numeros[posicao_maior_saldo];
        remover_conjunto_Sequencia(sequencia, posicao_maior_saldo);
        remover_conjunto_Sequencia(saldos, posicao_maior_saldo);

        if(posicao_maior_saldo <= 2){
            calcular_saldo(sequencia, 0, &saldo);
            saldos->numeros[0] = saldo;

        } else {
            if(posicao_maior_saldo > tamanho_anterior - 2){
                calcular_saldo(sequencia, sequencia->qtd_numeros - 1, &saldo);
                saldos->numeros[sequencia->qtd_numeros - 1] = saldo;

            } else{
                calcular_saldo(sequencia, posicao_maior_saldo - 2, &saldo);
                saldos->numeros[posicao_maior_saldo - 2] = saldo;

                calcular_saldo(sequencia, posicao_maior_saldo - 1, &saldo);
                saldos->numeros[posicao_maior_saldo - 1] = saldo;

            }
        }

    }

    printf("%ld\n", pontuacao);
    desalocar_Sequencia(saldos);
    return true;

}
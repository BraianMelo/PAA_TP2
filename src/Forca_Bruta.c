#include "../include/Forca_Bruta.h"

bool cacular_maior_valor(Sequencia *sequencia){
    int pontuacao = 0;
    int saldo;
    int maior_saldo;
    int posicao_maior_saldo;

    while(!sequencia_estah_vazia(sequencia)){
        calcular_saldo(sequencia, 0, &maior_saldo);
        posicao_maior_saldo = 0;

        for(int i = 1; i < sequencia->qtd_numeros; ++i){
            calcular_saldo(sequencia, i, &saldo);

            if(saldo > maior_saldo){
                maior_saldo = saldo;
                posicao_maior_saldo = i;
            }
        }

        pontuacao += sequencia->numeros[posicao_maior_saldo];
        remover_conjunto_Sequencia(sequencia, posicao_maior_saldo);

    }

    printf("%d\n", pontuacao);
    return true;
}

void calcular_saldo(Sequencia *sequencia, int posicao, int *saldo){
    *saldo = sequencia->numeros[posicao];
    
    if(posicao > 0)
        *saldo -= sequencia->numeros[posicao - 1];

    if(posicao < sequencia->qtd_numeros - 1)
        *saldo -= sequencia->numeros[posicao + 1];

}

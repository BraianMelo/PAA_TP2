#ifndef FORCA_BRUTA
#define FORCA_BRUTA

    #include <stdio.h>
    #include <stdbool.h>

    #include "../include/Sequencia.h"

    bool Forca_Bruta(Sequencia *sequencia);
    //O maior saldo da sequência é removido até a sequência estiver vazia 

    void calcular_saldo(Sequencia *sequencia, int posicao, int *saldo);
    //Saldo = (O valor da célula) - (Os valores das células vizinhas)

#endif
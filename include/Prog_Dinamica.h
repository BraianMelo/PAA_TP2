#ifndef PROG_DINAMICA
#define PROG_DINAMICA

    #include <stdio.h>
    #include <malloc.h>
    #include <stdbool.h>

    #include "../include/Sequencia.h"

    int maior(unsigned a, unsigned b); //Retornar o maior valor entre dois numeros
    bool metodo_Dinamico(Sequencia *sequencia, FILE **arquivo_saida);


#endif
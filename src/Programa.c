#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <unistd.h>

#include "../include/Sequencia.h"
#include "../include/Forca_Bruta.h"

#include "../include/Tempo.h"

int main(){

	struct timeval ini_tempo_total, fim_tempo_total;
    struct rusage inicio, fim;

	iniciar_contagem(&ini_tempo_total, &inicio);

	int tamanho, n;
	scanf("%d", &tamanho);

	if(tamanho > 100000)
		return 1;
	
	Sequencia *sequencia = criar_Sequencia();
	iniciar_Sequencia(sequencia, tamanho);
	
	for(int i = 0; i < tamanho; ++i){
		scanf("%d", &n);
		adicionar_numero_Sequencia(sequencia, n);
	}

	cacular_maior_valor(sequencia);

	desalocar_Sequencia(sequencia);

	parar_contagem(&fim_tempo_total, &fim);
	printar_tempo_gasto(&ini_tempo_total, &inicio, &fim_tempo_total, &fim);
	
	return 0;
}


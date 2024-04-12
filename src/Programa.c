#include <stdio.h>
#include <malloc.h>

#include "../include/Sequencia.h"
#include "../include/Forca_Bruta.h"

int main(){

	int tamanho, n;
	scanf("%d", &tamanho);
	
	Sequencia *sequencia = criar_Sequencia();
	iniciar_Sequencia(sequencia, tamanho);
	
	for(int i = 0; i < tamanho; ++i){
		scanf("%d", &n);
		adicionar_numero_Sequencia(sequencia, n);
	}

	imprimir_Sequencia(sequencia);

	remover_numero_Sequencia(sequencia, 1);

	imprimir_Sequencia(sequencia);

	desalocar_Sequencia(sequencia);
	
	return 0;
}


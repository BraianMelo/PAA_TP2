#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../include/Sequencia.h"
#include "../include/Alternativa.h"
#include "../include/Prog_Dinamica.h"

#include "../include/Tempo.h"

#define CAMINHO_ARQ_SAIDA "data/Output.txt"

bool receber_Argumentos(int argc, char *argv[], char *tipo, char **caminho_arq_entrada);
bool abrir_Arquivos(char **caminho_arq_entrada, FILE **arquivo_entrada, FILE **arquivo_saida);
bool fechar_Arquivos(FILE **arquivo_entrada, FILE **arquivo_saida);

int main(int argc, char *argv[]){

	char tipo, *caminho_arq_entrada;
	FILE *arquivo_entrada, *arquivo_saida;

	if(!receber_Argumentos(argc, argv, &tipo, &caminho_arq_entrada))
		return 1;

	if(!abrir_Arquivos(&caminho_arq_entrada, &arquivo_entrada, &arquivo_saida))
		return 1;

	struct timeval ini_tempo_total, fim_tempo_total;
    struct rusage inicio, fim;

	iniciar_contagem(&ini_tempo_total, &inicio);

	int tamanho, n;
	fscanf(arquivo_entrada, "%d", &tamanho);

	if(tamanho > 100000)
		return 1;
	
	Sequencia *sequencia = criar_Sequencia();
	iniciar_Sequencia(sequencia, tamanho);
	
	for(int i = 0; i < tamanho; ++i){
		fscanf(arquivo_entrada, "%d", &n);
		adicionar_numero_Sequencia(sequencia, n);
	}

	if(tipo == 'D'){
		printf("Programação Dinamica: \n");
		metodo_Dinamico(sequencia, &arquivo_saida);

	} else {
		printf("Metodo alternativo: \n");
		metodo_Alternativo(sequencia, &arquivo_saida);
	}
		
	desalocar_Sequencia(sequencia);

	parar_contagem(&fim_tempo_total, &fim);
	printar_tempo_gasto(&ini_tempo_total, &inicio, &fim_tempo_total, &fim);

	fechar_Arquivos(&arquivo_entrada, &arquivo_saida);

	return 0;
}


bool receber_Argumentos(int argc, char *argv[], char *tipo, char **caminho_arq_entrada){

	if(argc != 3){
		printf("Números de argumentos inválido! %d\n", argc);
		return false;
	}

	*tipo = argv[1][0];

	if(*tipo == 'D' || *tipo == 'd'){
		*tipo = 'D';

	} else if(*tipo == 'A' || *tipo == 'a'){
		*tipo = 'A';

	} else {
		printf("Erro! Use apenas D (dinâmico) ou A (alternativo) para indicar o método.\n");
		return false;
	}	

	*caminho_arq_entrada = argv[2];

	return true;
}

bool abrir_Arquivos(char **caminho_arq_entrada, FILE **arquivo_entrada, FILE **arquivo_saida){

	*arquivo_entrada = fopen(*caminho_arq_entrada, "r");

	if(*arquivo_entrada == NULL){
		printf("Arquivo de entrada não existe! \n");
		return false;
	}

	*arquivo_saida = fopen(CAMINHO_ARQ_SAIDA, "w");

	if(*arquivo_saida == NULL){
		printf("Error criando/abrindo caminho de saída! \n");
		fclose(*arquivo_entrada);
		return false;
	}

	return true;
}

bool fechar_Arquivos(FILE **arquivo_entrada, FILE **arquivo_saida){
	if(*arquivo_entrada == NULL)
		return false;
	fclose(*arquivo_entrada);

	if(*arquivo_saida == NULL)
		return false;
	fclose(*arquivo_saida);

	return true;
}



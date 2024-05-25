#!/bin/bash

# Lista de inputs
inputs=(5 9 10 50 100 1000 10000 100000)

# Arquivo de saída
output_file="data/Tempo_Alternativo.txt"

# Limpa o arquivo de saída se ele já existir
> $output_file

# Loop através de cada input
for input in "${inputs[@]}"; do
    echo "Executando ./bin/Programa com input $input" >> $output_file
    
    for i in {1..5}; do
        echo "Execução $i para input $input:" >> $output_file
        ./bin/tp2 A data/Inputs/input_${input}.txt >> $output_file
        echo "--------------------------------------------" >> $output_file 
    done
    
    echo "++++++++++++++++++++++++++++++++++++++++++++++++++++++" >> $output_file # Adiciona uma linha em branco entre as execuções
done

echo "Execuções concluídas. Resultados salvos em $output_file"
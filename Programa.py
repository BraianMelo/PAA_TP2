def maxPontuacao(a, n):
    if n == 0:
        return 0
    if n == 1:
        return a[0]
    
    dp = [0] * (n + 1)
    dp[1] = a[0]
    
    for i in range(2, n + 1):
        dp[i] = max(a[i - 1] + dp[i - 2], dp[i - 1])
    
    return dp[n]

def main():
    # Solicitar ao usuário que insira a sequência de inteiros
    sequencia = input("Digite a sequência de inteiros separados por espaços: ").split()
    
    # Converter os elementos da sequência para inteiros
    sequencia = list(map(int, sequencia))
    
    # Calcular o tamanho da sequência
    n = len(sequencia)
    
    # Calcular e imprimir a pontuação máxima
    pontuacao_maxima = maxPontuacao(sequencia, n)
    print("Pontuação máxima:", pontuacao_maxima)

if __name__ == "__main__":
    main()


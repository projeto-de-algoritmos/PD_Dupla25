# Resolve a questão Coin Change, do juiz online LeetCode
# Nível: Médio
# Link: https://leetcode.com/problems/coin-change

def coinChange(self, coins: List[int], amount: int) -> int:

    tam = len(coins)
    memo = []

    # define o array de memorização
    for valor_atual in range(amount + 1):

        if valor_atual == 0:
            memo.append(0)                      # caso base

        else:                                   # considera todos como valor máximo possível de entrada
            memo.append(2147483650)

    for valor_atual in range(amount + 1):

        if valor_atual == 0:
            continue

        else:

            for qtd_atual in range(tam):

                if coins[qtd_atual] <= valor_atual:

                    qtd_necessaria = memo[valor_atual - coins[qtd_atual]]

                    if qtd_necessaria + 1 < memo[valor_atual] and qtd_necessaria != 2147483650:
                        memo[valor_atual] = qtd_necessaria + 1

    if memo[amount] == 2147483650:
        return(-1)
    else:
        return(memo[amount])

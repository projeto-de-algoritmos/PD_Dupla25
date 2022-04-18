# Resolve a questão Triangle, do juiz online LeetCode
# Nível: Médio
# Link: https://leetcode.com/problems/triangle/

def minimumTotal(self, triangle: List[List[int]]) -> int:

    ultima_linha = len(triangle) - 1
    tabela_somas = []

    for i in range(len(triangle[ultima_linha])):
        tabela_somas.append(triangle[ultima_linha][i])

    # a linha atual que recebera a soma
    # é sempre um a menos que a linha de verficação de qual valor é menor
    # pois é a que irá receber o valor calculado
    linha_atual = len(triangle) - 2

    while (1):

        if linha_atual == -1:       # se ja passou do topo do triangulo
            break

        else:

            i = 0
            tam_linha = len(triangle[linha_atual])

            while (1):

                if i == tam_linha:
                    break

                else:

                    # escolhe o menor valor entre dois analisados da linha atual de tabela_somas
                    menor = min(tabela_somas[i], tabela_somas[i + 1])

                    # soma esse menor com o pai no triangulo logo acima
                    tabela_somas[i] = triangle[linha_atual][i] + menor

                i += 1

            linha_atual -= 1        # sobe de linha no triangulo

    return tabela_somas[0]          # menor valor de somas ao chegar no topo

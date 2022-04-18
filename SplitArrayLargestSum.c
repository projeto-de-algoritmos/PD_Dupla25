#include<stdio.h>

// A resposta comeca aqui
// Essa funcao pega o maior numero entre B e C, e com esse resultado ele pega o menor entre A e B, e retorna esse valor
int menorMaximo(int a, int b, int c){
    int res = b;
    if(res < c)
        res = c;
    if(a < res)
        res = a;
    return res;
}

int splitArray(int* nums, int numsSize, int m){
    // Cria um vetor auxiliar e inicializo na primeira posicao com o valor de nums na primeira posicao
    int aux[numsSize];
    aux[0] = nums[0];
    // Nas proximas posicoes insere a soma do valor da posicao anterior do aux com a posicao atual do nums
    for (int i = 1; i < numsSize; i++)
        aux[i] = nums[i] + aux[i - 1];
    
    // 
    for (int j = 2; j <= m; j++) {
        for (int k = numsSize - 1; k >= j - 1; k--) {
            // Cria um minimo grande para sempre atualizar quando necessario
            int minimo = 99999999;
            // Vai pegando o ultimo valor de nums 
            int left = nums[k];
            for (int l = k - 1; l >= j - 2; l--) {
                // Chama a funcao menorMaximo
                minimo =  menorMaximo(minimo, aux[l], left);
                // Incrementa com o valor da esquerda do nums
                left += nums[l];
                // Se o minimo for menor quer a ultima posicao do vetor nums, ele termina o "for"
                if (left >= minimo) {
                    break;
                }
            }
            aux[k] = minimo;
        }
    }
    
    return aux[numsSize - 1];
}
// A resposta termina aqui

int main(){
    int nums[5] = {1,2,3,4,5}, m = 2;
    printf("%d\n", splitArray(nums, 5, m));
}
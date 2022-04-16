#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// A resposta comeca aqui
bool canJump(int* nums, int numsSize){
    
    // se o tamanho eh 1 ou 0, nao eh necessario pular, retorna true
    if(numsSize==1 || numsSize==0) return true;
    // se a primeira posicao for 0, ele nao pode pular, retorna false
    if(nums[0]==0) return false;
    
    // cria um vetor auxiliar e inicializa com 0 na primeira posicao
    int aux[numsSize];
    aux[0] = 0;
    
    
    for(int i=1;i<numsSize;i++){
        // verifica, entre o aux e nums, qual possui um valor maior na posicao anterior
        // depois eu armazeno o maior valor-1 na posicao atual, pois conta como um pulo
        if(nums[i-1] > aux[i-1])
            aux[i] = nums[i-1]-1;
        else
            aux[i] = aux[i-1]-1;
        // caso a posicao atual seja menor que zero, então acabou as possibilidades de pulo, retorna false
        if(aux[i]<0)
            return false;
    }
    return true;
}
// A resposta termina aqui

int main()
{
    int nums[1000] = {2,3,1,1,4}, numsSize = 5;
    for(int i=0;i<numsSize;i++)
    printf("%d ", nums[i]);
    
    if(canJump(nums, numsSize))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}

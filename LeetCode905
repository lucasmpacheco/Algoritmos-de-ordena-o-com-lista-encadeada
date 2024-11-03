int* sortArrayByParity(int* nums, int numsSize, int* returnSize) {
    int* resultado = (int*)malloc(numsSize * sizeof(int)); // Aloca memória para o array resultante
    int PosPar = 0; // Posição inicial para armazenar números pares no início do array
    int PosÍmpar = numsSize - 1; // Posição inicial para armazenar números ímpares no final do array

    // Percorre cada elemento em nums para verificar se é par ou ímpar
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] % 2 == 0) { 
            resultado[PosPar] = nums[i]; // Armazena o número par na posição de 'PosPar'
            PosPar++; // Move a posição de 'PosPar' para a direita
        } else {
            resultado[PosÍmpar] = nums[i]; // Armazena o número ímpar na posição de 'PosÍmpar'
            PosÍmpar--; // Move a posição de 'PosÍmpar' para a esquerda
        }
    }
    *returnSize = numsSize; // Define o tamanho do array de retorno
    return resultado; // Retorna o array com números ordenados por paridade
}

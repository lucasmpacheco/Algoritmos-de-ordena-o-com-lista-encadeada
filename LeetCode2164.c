int* sortEvenOdd(int* nums, int numsSize, int* returnSize) {
    int* resultado = (int*)malloc(numsSize * sizeof(int));

    // Copiar o array original para manter os valores
    for (int i = 0; i < numsSize; i++) {
        resultado[i] = nums[i];
    }
    
    if (numsSize <= 2) {
        *returnSize = numsSize;
        return nums;
    } else {
        // Ordenar pares (índices 0, 2, 4, ...) em ordem crescente
        for (int i = 0; i < numsSize; i += 2) {
            for (int j = i + 2; j < numsSize; j += 2) {
                if (resultado[i] > resultado[j]) {
                    int temp = resultado[i];
                    resultado[i] = resultado[j];
                    resultado[j] = temp;
                }
            }
        }

        // Ordenar ímpares (índices 1, 3, 5, ...) em ordem decrescente
        for (int i = 1; i < numsSize; i += 2) {
            for (int j = i + 2; j < numsSize; j += 2) {
                if (resultado[i] < resultado[j]) {
                    int temp = resultado[i];
                    resultado[i] = resultado[j];
                    resultado[j] = temp;
                }
            }
        }
    }

    *returnSize = numsSize;
    return resultado;
}

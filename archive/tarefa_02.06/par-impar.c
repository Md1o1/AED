/* Fazer um programa para:
> ler o arquivo gerado anteriormente e armazenar os valores pares em um arquivo e os impares em outro arquivo e utilize o formato txt*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    const char *inputFilePath = "D:/Projects/AED/fibonacci.txt";
    FILE *fptr = fopen(inputFilePath, "r");
    if (fptr == NULL) {
        printf("Erro ao abrir o arquivo 'fibonacci.txt'!\n");
        return 1;
    }

    const char *outputFilePath1 = "D:/Projects/AED/pares.txt";
    const char *outputFilePath2 = "D:/Projects/AED/impares.txt";  
    FILE *fpares = fopen(outputFilePath1, "w");
    FILE *fimpares = fopen(outputFilePath2, "w");
    
    if (fpares == NULL || fimpares == NULL) {
        printf("Erro ao abrir os arquivos 'pares.txt' ou 'impares.txt'!\n");
        fclose(fptr);
        return 1;
    }

    // Loop para ler cada número e separar os pares e os ímpares
    unsigned long long int num;
    while (fscanf(fptr, "%llu,", &num) != EOF) {
        if (num % 2 == 0) {
            fprintf(fpares, "%llu\n", num);
        } else {
            fprintf(fimpares, "%llu\n", num);
        }
    }

    fclose(fptr);
    fclose(fpares);
    fclose(fimpares);
    printf("Números pares salvos em 'pares.txt' e ímpares em 'impares.txt'\n");
    return 0;
}
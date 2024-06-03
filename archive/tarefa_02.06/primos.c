/* Fazer um programa para:
> ler o arquivo inicialmente gerado e armazenar apenas os primos em um arquivo, no formato txt. */
#include <stdio.h>
#include <stdbool.h>

bool numPrimo(unsigned long long int num) {
    if (num <= 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    for (unsigned long long int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    const char* inputFilePath = "D:/Projects/AED/fibonacci.txt";
    const char* outputFilePath = "D:/Projects/AED/primos.txt";

    FILE *fptr = fopen(inputFilePath, "r");
    FILE *fprimos = fopen(outputFilePath, "w");

    if (fptr == NULL || fprimos == NULL) {
        printf("Erro ao abrir os arquivos!\n");
        return 1;
    }
    // Loop para ler cada número e separar os primos
    unsigned long long int num;
    while (fscanf(fptr, "%llu,", &num) != EOF) {
        if (numPrimo(num)) {
            fprintf(fprimos, "%llu\n", num);
        }
    }

    fclose(fptr);
    fclose(fprimos);
    printf("Números primos salvos em 'primos.txt'\n");
    return 0;
}

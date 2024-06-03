/* Fazer um programa para: 
> ler um arquivo contendo um conjunto de valores(fibonacci.txt)(flag -1) e verifique para cada valor se ele se encontra ou não no
arquivo gravado com a serie. Caso não exista deverá mostrar o valor anterior e o posterior a esse valor. 
Exemplo: caso seja lido o valor 8 – deverá ser mostrada a informação que o valor 8 está no arquivo na posição 6, 
caso o valor lido seja o 15 deverá ser mostrada a informação o valor 15 não está no arquivo, valores mais próximos: 13 e 21. 
Grave esses resultados em um arquivo no formato txt. */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Função para encontrar um valor na série de Fibonacci e obter valores adjacentes se não encontrado
void encontrarValor(unsigned long long int *fibonacci, int size, unsigned long long int valor, FILE *output) {
    int pos = -1;
    for (int i = 0; i < size; i++) {
        if (fibonacci[i] == valor) {
            pos = i;
            break;
        }
    }
    if (pos != -1) {
        fprintf(output, "O valor %llu está no arquivo na posição %d.\n", valor, pos + 1);
    } else {
        int lower = -1, upper = -1;
        for (int i = 0; i < size; i++) {
            if (fibonacci[i] < valor) {
                lower = i;
            }
            if (fibonacci[i] > valor) {
                upper = i;
                break;
            }
        }
        if (lower != -1 && upper != -1) {
            fprintf(output, "O valor %llu não está no arquivo. Valores mais próximos: %llu e %llu.\n",
                    valor, fibonacci[lower], fibonacci[upper]);
        } else if (lower != -1) {
            fprintf(output, "O valor %llu não está no arquivo. Valor mais próximo: %llu.\n",
                    valor, fibonacci[lower]);
        } else if (upper != -1) {
            fprintf(output, "O valor %llu não está no arquivo. Valor mais próximo: %llu.\n",
                    valor, fibonacci[upper]);
        } else {
            fprintf(output, "O valor %llu não está no arquivo e não há valores próximos.\n", valor);
        }
    }
}

int main() {
    const char *inputFilePath = "D:/Projects/AED/fibonacci.txt";
    const char *valoresFilePath = "D:/Projects/AED/valoresAverificar.txt"; // Arquivo de entrada com valores a serem verificados
    const char *outputFilePath = "D:/Projects/AED/resultadoValores.txt"; // Arquivo de saída para os resultados
    const int maxSize = 100; // Ajuste conforme necessário

    unsigned long long int fibonacci[maxSize];
    int size = 0;

    // Lendo a série de Fibonacci do arquivo
    FILE *fibonacciFile = fopen(inputFilePath, "r");
    if (fibonacciFile == NULL) {
        printf("Erro ao abrir o arquivo %s!\n", inputFilePath);
        return 1;
    }
    while (size < maxSize && fscanf(fibonacciFile, "%llu,", &fibonacci[size]) != EOF) {
        size++;
    }
    fclose(fibonacciFile);

    FILE *valoresFile = fopen(valoresFilePath, "r");
    if (valoresFile == NULL) {
        printf("Erro ao abrir o arquivo %s!\n", valoresFilePath);
        return 1;
    }

    FILE *outputFile = fopen(outputFilePath, "w");
    if (outputFile == NULL) {
        printf("Erro ao abrir o arquivo %s!\n", outputFilePath);
        fclose(valoresFile);
        return 1;
    }

    unsigned long long int valor;
    while (fscanf(valoresFile, "%llu", &valor) != EOF && valor != (unsigned long long int)-1) {
        encontrarValor(fibonacci, size, valor, outputFile);
    }

    fclose(valoresFile);
    fclose(outputFile);

    printf("Resultados salvos em '%s'\n", outputFilePath);
    return 0;
}


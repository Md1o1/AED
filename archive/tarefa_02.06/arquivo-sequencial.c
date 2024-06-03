/* Fazer um programa com um menu para:
• gravar em um arquivo, no formato txt, os 64 primeiros valores da série: 1,1,2,3,5,8,13,21...
• ler o arquivo gerado anteriormente e armazenar os valores pares em um arquivo e os impares em outro arquivo
utilize o formato txt
• ler o arquivo inicialmente gerado e armazenar apenas os primos em um arquivo, no formato txt.
• leia um arquivo contendo um conjunto de valores (flag -1) e verifique para cada valor se ele se encontra ou não no
arquivo gravado com a serie. Caso não exista deverá mostrar o valor anterior e o posterior a esse valor. Exemplo: caso
seja lido o valor 8 – deverá ser mostrada a informação o valor 8 está no arquivo na posição 6, caso o valor lido seja o
15 – deverá ser mostrada a informação o valor 15 não está no arquivo, valores mais próximos: 13 e 21. Grave esses
resultados em um arquivo no formato txt. */

#include <stdio.h>
#include <stdlib.h>

void fibonacci();
void pares_impares();
void primos();
void verificar();

int main() {
    int op;
    printf("Digite o valor correspondente a uma acao:\n [1] imprimir serie de valores(fibonacci); \n [2] Ler o arquivo gerado e separar os valores pares e impares; \n [3] Ler o arquivo gerado e separar os valores primos; \n [4] ler o arquivo de teste e verificar se os valores existem na serie do arquivo gerado, se nao existir o programa exibe os valores proximos.\n");
    scanf("%d", &op);
    switch (op)
    {
    case 1:
        fibonacci();
        break;
    case 2:
        pares_impares();       
        break;
    case 3:
        primos();
        break;
    case 4:
        verificar();
        break;
       }
    return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void fibonacci(){
    int n = 64;
    unsigned long long int fib1 = 1, fib2 = 1;
    unsigned long long int next;

    //substituir o caminho abaixo para o caminho do arquivo onde deseja ser salvo desejado
    const char *inputFilePath = "D:/Projects/AED/fibonacci.txt";
    FILE *fptr = fopen(inputFilePath, "w");

    if (fptr == NULL) {
        printf("Erro ao abrir o arquivo!\n");        
    }
    fprintf(fptr, "%llu, %llu", fib1, fib2);

    for (int i = 3; i <= n; i++){
        next = fib1 + fib2;
        fprintf(fptr, ", %llu", next);
        fib1 = fib2;
        fib2 = next;
    }
    fclose(fptr);
    printf("Sequencia salva em 'fibonacci.txt'\n");
   
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void pares_impares(){
    const char *inputFilePath = "D:/Projects/AED/fibonacci.txt";
    FILE *fptr = fopen(inputFilePath, "r");
    if (fptr == NULL) {
        printf("Erro ao abrir o arquivo 'fibonacci.txt'!\n");
    }
    const char *outputFilePath1 = "D:/Projects/AED/pares.txt";
    const char *outputFilePath2 = "D:/Projects/AED/impares.txt";  
    FILE *fpares = fopen(outputFilePath1, "w");
    FILE *fimpares = fopen(outputFilePath2, "w");
    if (fpares == NULL || fimpares == NULL) {
        printf("Erro ao abrir os arquivos 'pares.txt' ou 'impares.txt'!\n");
        fclose(fptr);
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
    printf("Numeros pares salvos em 'pares.txt' e impares em 'impares.txt'\n");
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void primos(){
    const char* inputFilePath = "D:/Projects/AED/fibonacci.txt";
    const char* outputFilePath = "D:/Projects/AED/primos.txt";

    FILE *fptr = fopen(inputFilePath, "r");
    FILE *fprimos = fopen(outputFilePath, "w");

    if (fptr == NULL || fprimos == NULL) {
        printf("Erro ao abrir os arquivos!\n");
    }
    unsigned long long int num;
    // Loop para ler cada número e separar os primos
    while (fscanf(fptr, "%llu,", &num) != EOF) {
        // Verificação de primo
        int numPrimo = 1; // Assumimos que o número é primo
        if (num <= 1) {
            numPrimo = 0; // Números <= 1 não são primos
        } else if (num == 2) {
            numPrimo = 1;
        } else if (num % 2 == 0) {
            numPrimo = 0;
        } else {
            for (unsigned long long int i = 3; i * i <= num; i += 2) {
                if (num % i == 0) {
                    numPrimo = 0;
                    break;
                }
            }
        }
        if (numPrimo) {
            fprintf(fprimos, "%llu\n", num);
        }
    }
    fclose(fptr);
    fclose(fprimos);
    printf("Numeros primos salvos em 'primos.txt'\n");
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void verificar(){
   /* const char* inputFilePath = "D:/Projects/AED/fibonacci.txt";
    const char* inputFilePath1 = "D:/Projects/AED/teste.txt";
    const char* outputFilePath = "D:/Projects/AED/resultadoTeste.txt";
    FILE *fptr = fopen(inputFilePath, "r");
    FILE *fptr1 = fopen(inputFilePath1, "r");

    if (fptr == NULL || fptr1 == NULL){
        printf("Erro ao abrir o arquivo fibonacci.txt e teste.txt.\n");
    }
    int n, i, valorTeste, menorProximo, maiorProximo;
    // Ler os valores do arquivo fibonacci.txt
    fscanf(fptr, "%d", &n);
    for (i = 0; i < n; i++) {
        fscanf(inputFilePath, "%d", &fibonacci[i]);
    }
    // Ler o valor do arquivo teste.txt
    fscanf(fptr1, "%d", &valorTeste);

    // Verificar se o valor existe no vetor fibonacci
    int encontrado = 0;
    for (i = 0; i < n; i++) {
        if (fibonacci[i] == valorTeste) {
            fprintf(inputFilePath1, "O valor %d existe no arquivo!\n", valorTeste);
            encontrado = 1;
            break;
        }
    }

    // Se não encontrado, encontrar os valores mais próximos
    if (!encontrado) {
        menorProximo = maiorProximo = fibonacci[0];
        for (i = 1; i < n; i++) {
            if (fibonacci[i] < valorTeste) {
                menorProximo = fibonacci[i];
            } else {
                maiorProximo = fibonacci[i];
                break;
            }
        }
        fprintf(outputFilePath, "O valor desejado não existe, o valor menor mais próximo é %d e o valor maior mais próximo é %d\n", menorProximo, maiorProximo);
    }

    // Fechar os arquivos
    fclose(fptr);
    fclose(fptr1);
    fclose(outputFilePath);

    printf("Resultado salvo em resultadoTeste.txt.\n"); */
    printf("Funcao nao implementada, nao consegui resolver os bugs no codigo a tempo de entregar a tarefa.\n");
}
/* Fazer um programa para:
> gravar em um arquivo, no formato txt, os 64 primeiros valores da série: 1,1,2,3,5,8,13,21... */
#include <stdio.h>

int main(){
    int n = 64;
    unsigned long long int fib1 = 1, fib2 = 1;
    unsigned long long int next;

    const char *inputFilePath = "D:/Projects/AED/fibonacci.txt";
    FILE *fptr = fopen(inputFilePath, "w");

    if (fptr == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }
    fprintf(fptr, "%llu, %llu", fib1, fib2);

    for (int i = 3; i <= n; i++){
        next = fib1 + fib2;
        fprintf(fptr, ", %llu", next);
        fib1 = fib2;
        fib2 = next;
    }
    fclose(fptr);
    printf("Sequência salva em 'fibonacci.txt'\n");
    return 0;
}
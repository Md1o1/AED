/************************************************************************************************
Escreva um algoritmo que declare um número entre 1 e 20 e peça para o usuário adivinhar qual
é. A cada palpite o programa diz se o número foi mais alto ou mais baixo que o número correto.
Utilize a estrutura e repetição do-while
*************************************************************************************************/
#include <stdio.h>
#include <time.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, " ");
    int numero, palpite;
    srand(time(0)); //alimenta o gerador de numeros aleatorios usando o relógio do sistema
    numero = rand() % 20 + 1; //gera um numero aleatorio entre 1 e 20
    //printf("O número gerado foi %d\n", numero);
    do {
        printf("Insira um número entre 1 e 20:\n");
        scanf("%d", &palpite);
        if (palpite > numero) {
            printf("O número inserido é menor.\n");
        } else if (palpite < numero) {
            printf("O número inserido é maior.\n");
        } else {
            printf("Parabéns! você acertou.\n");
        }
    } while (palpite != numero);

    return 0;
}
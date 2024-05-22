#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void soma();
void subtracao();
void multiplicacao();
void divisao();

int main() {
    int operacao;
    printf("selecione uma operacao: soma(1), subtracao(2), multiplicacao(3), divisao(4). \n");
    scanf("%d", &operacao);

    switch (operacao) {
        case 1:
            soma();
            break;
        case 2:
            subtracao();
            break;
        case 3:
            multiplicacao();
            break;
        case 4:
            divisao();
            break;
        default:
            printf("Error: Invalid operator.\n");
            break;
    }
    return 0;
}

void soma(){
    int a, b, soma;
    printf("Digite um valor: ", a);
    scanf("%d", &a); 
    printf("Digite outro valor: ", b);
    scanf("%d", &b);
    soma = a + b;
    printf("A soma de %d + %d = %d\n", a, b, soma);
}
void subtracao(){
    int a, b, subtracao;
    printf("Digite um valor: ", a);
    scanf("%d", &a); 
    printf("Digite outro valor: ", b);
    scanf("%d", &b);
    subtracao = a - b;
    printf("A subtracao de %d - %d = %d\n", a, b, subtracao);
}
void multiplicacao(){
    int a, b, multiplicacao;
    printf("Digite um valor: ", a);
    scanf("%d", &a); 
    printf("Digite outro valor: ", b);
    scanf("%d", &b);
    multiplicacao = a * b;
    printf("A multiplicacao de %d * %d = %d\n", a, b, multiplicacao);
}
void divisao(){
    int a, b, divisao;
    printf("Digite um valor: ", a);
    scanf("%d", &a); 
    printf("Digite outro valor: ", b);
    scanf("%d", &b);
    divisao = a / b;
    printf("A divisao de %d / %d = %d\n", a, b, divisao);
}
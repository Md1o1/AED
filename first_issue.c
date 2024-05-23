#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void leitura();
void soma();
void subtracao();
void multiplicacao();
void divisao();

int a, b;
float r;

int main()
{
    int op;
    printf("selecione uma operacao: soma(1), subtracao(2), multiplicacao(3), divisao(4). \n");
    scanf("%d", &op);
    leitura();
    switch (op)
    {
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
       }
    printf("O resultado da operacao de %d + %d = %f\n", a, b, r);
    return 0;
}

void leitura()
{
    printf("Digite um valor: ", a);
    scanf("%d", &a);
    printf("Digite outro valor: ", b);
    scanf("%d", &b);
}
void soma()
{
    r = a + b;
}
void subtracao()
{
    r = a - b;
}
void multiplicacao()
{
    r = a * b;
}
void divisao()
{
    r = a / b;
}
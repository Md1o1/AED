/*************************************************************************************
Desenvolva um algoritmo que imprima os n primeiros elementos da série de Fibonacci.
Ex.: Se n = 10, imprimir os 10 primeiros números da sequência de Fibonacci.
*************************************************************************************/
#include <stdio.h>

int main(){
    int n, a, b, c;
    a = 0;
    b = 1;
    c = 0;
    printf("Digite um número: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        printf("%d ", c);
        c = a + b;
        a = b;
        b = c;
    }
    printf("\n");
    return 0;
}
#include <stdio.h>

void somaValores();

int main() {
    somaValores();
    return 0;
}
void somaValores() {
    int a, b, soma;
    printf("Digite um valor: ", a);
    scanf("%d", &a); 
    printf("Digite outro valor: ", b);
    scanf("%d", &b);
    soma = a + b;
    printf("A soma de %d + %d = %d\n", a, b, soma);
}
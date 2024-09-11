/*******************************************************************************
Escreva um programa que verifique se um número é palíndromo.
Um número é palíndromo se continua o mesmo caso seus dígitos sejam invertidos.
Exemplos: 454 ou 10501
*******************************************************************************/
#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, " ");
    int numero, numero_invertido, resto, numero_original;
    numero_invertido = 0;
    printf("Digite um número: ");
    scanf("%d", &numero);
    numero_original = numero;
    while(numero > 0){
        resto = numero % 10;
        numero_invertido = numero_invertido * 10 + resto;
        numero /= 10;
    }
    if(numero_original == numero_invertido){
        printf("O número %d é palíndromo.\n", numero_original);
    } else {
        printf("O número %d não é palíndromo.\n", numero_original);
    }
    return 0;
}
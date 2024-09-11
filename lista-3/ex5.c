/********************************************************************************************
Escreva um programa que leia a altura de 5 homens e 5 mulheres, e imprima a média de altura
masculina, feminina e geral
********************************************************************************************/
#include <stdio.h>

int main(){
    float altura, media_masc, media_fem, media_geral;
    media_masc = 0;
    media_fem = 0;
    media_geral = 0;
    for(int i = 0; i < 5; i++){
        printf("Digite a altura do homem %d: ", i+1);
        scanf("%f", &altura);
        media_masc += altura;
    }
    for(int i = 0; i < 5; i++){
        printf("Digite a altura da mulher %d: ", i+1);
        scanf("%f", &altura);
        media_fem += altura;
    }
    media_geral = (media_masc + media_fem) / 10;
    media_masc /= 5;
    media_fem /= 5;
    printf("Média de altura masculina: %.2f\n", media_masc);
    printf("Média de altura feminina: %.2f\n", media_fem);
    printf("Média de altura geral: %.2f\n", media_geral);
    return 0;
}
/*********************************************************************************************
 Escreva um programa que recebe um ano do usuário e imprime na tela todos os anos bissextos
do ano 1 até o ano digitado. Utilize a estrutura de repetição while.
*********************************************************************************************/
#include <stdio.h>

int main(){
    int ano, bissexto;
    bissexto = 1; 
    printf("Digite um ano: ");
    scanf("%d", &ano);
    while(bissexto <= ano){
        if(bissexto % 4 == 0 && bissexto % 100 != 0 || bissexto % 400 == 0){
            printf("%d\n", bissexto);
        }
        bissexto++;
    }
    return 0;
}
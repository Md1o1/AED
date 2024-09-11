/*************************************************************************************
Escreva um programa que leia dois inteiros e imprima um retângulo com as dimensões
digitadas. Ex.: para os números 3 e 5, seria impresso:
*****
*   *
*****
Enquanto que para os números 5 e 3 seria impresso:
***
* *
* *
* *
***
**************************************************************************************/
#include <stdio.h>

int main(){
    int largura, altura;
    printf("Digite a largura do retângulo: ");
    scanf("%d", &largura);
    printf("Digite a altura do retângulo: ");
    scanf("%d", &altura);
    for(int i = 0; i < altura; i++){
        for(int j = 0; j < largura; j++){
            if(i == 0 || i == altura - 1 || j == 0 || j == largura - 1){
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;    
}
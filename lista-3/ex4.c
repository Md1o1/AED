/***********************************************************************************
Desenvolva um algoritmo que leia um valor n entre 0 e 9 e escreva na tela a tabuada
correspondente do número. Para o número 4 por exemplo, seria printado:
4 x 0 = 0
4 x 1 = 4
4 x 2 = 8
...
Utilize a estrutura e repetição for.
************************************************************************************/
#include <stdio.h>

int main(){
    int n;
    printf("Digite um número entre 0 e 9: ");
    scanf("%d", &n);
    for(int i = 0; i <= 10; i++){
        printf("%d x %d = %d\n", n, i, n*i);
    }
    return 0;
}
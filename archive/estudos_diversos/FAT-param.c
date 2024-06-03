#include <stdio.h>
#include <stdlib.h>

//calcular o fatorial de um numero

int FAT;
void fatorial(int numero);
int main(){   
    int numero;
    printf("Digite um numero: ");
    scanf("%d", &numero);
    fatorial(numero);
    printf("o fatorial de %d é %d\n", numero, FAT);
    return 0;
}
void fatorial(int numero){
    int i;
    FAT = 1;
    for(int i = 1; i <= numero; i++){
        FAT = FAT * i;
    }
}
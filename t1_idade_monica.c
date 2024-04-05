#include <stdio.h>

int main(){
    int M;
    int A;
    int B;
    int soma;

    scanf("%d", &M); //scan idade monica
    scanf("%d", &A); //scan idade filho 1
    scanf("%d", &B); //scan idade filho 2
    soma = M + A;

    printf("%d\n", soma);
    return 0;
}
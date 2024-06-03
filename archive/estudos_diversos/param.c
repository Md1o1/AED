#include <stdio.h>

void improve();

int main(){
    int a;
    printf("Digite um valor: ");
    scanf("%d", &a);
    improve(a);
    return 0;
}
void improve(int a){
   a = a +1;
   printf("O valor de a e: %d\n", a);
}
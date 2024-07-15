#include <stdio.h>
#include <math.h>

int main(){
    int a;
    scanf("%d", &a);

if (a == 1) { // atribuição do numero ao dia
    printf("Domingo\n");
}

if (a == 2) {
    printf("Segunda\n");
}

if (a == 3) {
    printf("Terca\n");
}

if (a == 4) { 
    printf("Quarta\n");
}

if (a == 5) {
    printf("Quinta\n");
}

if (a == 6) {
    printf("Sexta\n");
}

if (a == 7) {
    printf("Sabado\n");
}
if (1 > a || 7 < a) {
    printf("Invalido");
}
return 0;
}
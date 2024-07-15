#include <stdio.h>

int main (){
    int x;
    scanf ("%d", &x);
    int a, b, maior = 0, menor = 999999, npar = 0, nimpar = 0;
    float media, soma = 0;
for (a = 1; a <= x; a++) {
    scanf ("%d", &b);
    soma += b;
    if (b % 2 == 0){
        npar++;
    }
    if (b % 2 != 0) {
        nimpar++;
    }
    if (b < menor){
        menor = b;
    }
    if (b > maior) {
        maior = b;
    }
}
media = soma / x;
printf("%d %d %d %d %.6f", maior, menor, npar, nimpar, media);

return 0;
}
#include <stdio.h>

int main (){

    int i, maior = 0, limite, cont = 0;
    float x, soma = 0, media;

    for (limite = 0; limite < 999999; limite++) {
        scanf("%f", &x);
        cont++;
        soma += x;
        media = soma / cont;
        if (x > maior) {
            maior = x;
        }
        if (x == 0) {
            break;
        }
        printf ("%d %.6f\n", maior, media);
    }
    return 0;
}
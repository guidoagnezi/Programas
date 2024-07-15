#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int verificaPrimo(int n);
int transformaPrimo(int n);
int verificaNegativo(int n);

int main(){
    
int x, y;
int linha = 1, coluna = 1;
int primo, neg;
int z;
int z2;

    scanf("%d %d", &x, &y);
    scanf("%*c");

    for (linha = 1; linha <= x; linha++) {

        for (coluna = 1; coluna <= y; coluna++) {

            scanf("%d", &z);


            primo = verificaPrimo(z);
            neg = verificaNegativo(z);

            if (primo == 1) {
                printf("%d ", z);
                continue;
            }

            if (neg == 1) {
            z2 = (transformaPrimo(z)) * -1;
            if (z2 < -32000){
                printf("%d ", z);
            }
            else {
            printf("%d ", z2);
            }
            }

            if (neg == 0) {
            z2 = transformaPrimo(z);
            if (z2 > 32000){
                printf("%d ", z);
            }
            else {
            printf("%d ", z2);
            }
            }
        }
        if (linha != x){
            printf("\n");
    }
    }

return 0;
}


int verificaPrimo(int n) {

    int den = 1, cont = 0;

    for (den = 1; den <= n; den++) {
        if (n % den == 0) {
            cont++;
        }
    }
    if (cont == 2) {
        return 1;
    }
    else {
        return 0;
    }
}

int verificaNegativo(int n) {
    if (n < 0) {
        return 1;
    }
    else {
        return 0;
    }
}

int transformaPrimo(int n) {

    int den = 1, cont = 0;
    n = abs(n);

    for (n+=1; 1; n++) {
        cont = 0;
    for (den = 1; den <= n; den++) {
        if (n % den == 0) {
            cont++;
        }
    }
    if (cont == 2) {
        return n;
    }
    }
}
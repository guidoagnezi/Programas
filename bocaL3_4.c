#include <stdio.h>

void ImprimeMultiplos(int num, int max);
int EhPrimo (int num);


int main (){

    int x, y, ver;
    scanf("%d %d", &x, &y);

    for (x+=1; x < y; x++) {
        ver = EhPrimo(x);
        if (ver == 1) {
            printf("%d\n", x);
            ImprimeMultiplos(x, y);
        }
    }  
return 0;
}

int EhPrimo(int num) {
    int den, cont = 0;

    for (den = 1; den <= num; den++) {
    
        if (num % den == 0) {
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

void ImprimeMultiplos(int num, int max) {
    int x = num, tm = 0;
    for (num+=1; num < max; num++) {
        if (num % x == 0) {
            tm = 1;
            printf("%d ", num);
        }
    }
    if (tm == 0) {
        printf("*\n");
    }
    else {
    printf("\n");
    }
}
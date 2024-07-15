#include <stdio.h>

int EhPrimo(int num);

int main (){

    int x, y, ver;
    scanf("%d %d", &x, &y);

    for (x+=1; x < y; x++) {

    ver = EhPrimo(x);
    if (ver == 1) {
        printf("%d ", x);
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
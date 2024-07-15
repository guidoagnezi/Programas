#include <stdio.h>

int InverteNumero(int num);
int EhIgual(int a, int b);

int main(){

    int num, invertido, cont = 0, val;

    while(scanf("%d", &num) == 1) {

        invertido = InverteNumero(num);

        if (EhIgual(num, invertido)) {
            cont++;
        }

    }
    printf("COUNT:%d", cont);

return 0;
}

int EhIgual(int a, int b) {

    if (a == b) {
        return 1;
    }
    else {
        return 0;
    }
}

int InverteNumero(int num) {

int digito, invertido = 0;

    while (num != 0) {
        digito = num % 10;
        num = num / 10;
        invertido = (invertido * 10) + digito;
    }

    return invertido;
}
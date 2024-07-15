#include <stdio.h>

int EhPrimo(int num);
int MaiorDigitoPrimo(int num);

int main (){

    int num, mdp;
    int soma = 0;

    while (scanf("%d", &num) == 1) {

        mdp = MaiorDigitoPrimo(num);
        soma = soma + mdp;

    }

    printf("SOMA:%d", soma);

return 0;
}

int MaiorDigitoPrimo(int num) {

int digito, mdp = 0;

    while (num != 0) {

        digito = num % 10;
        if (EhPrimo(digito)) {

            if (digito > mdp) {
                mdp = digito;
            }
        }
        num = num / 10;
    }
    return mdp;
}

int EhPrimo(int num) {

    int den, cont = 0;

    for (den = 1; den <= num; den++) {

        if (num % den == 0) {
            cont++;
        }
    }
    if (cont == 2){
        return 1;
    }
    else {
        return 0;
    }
}
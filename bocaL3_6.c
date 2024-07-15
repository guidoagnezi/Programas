#include <stdio.h>

int EhPalindromo (int num);

int main (){

    int x, ver;
    
    while (scanf("%d", &x) == 1) {

        ver = EhPalindromo(x);
        if (ver == 1) {
            printf("S\n");
        }
        if (ver == 0) {
            printf("N\n");
        }
    }
return 0;
}

int EhPalindromo(int num) {

    int reverso = 0, digito, x = num;

        while(num != 0) {

        digito = num % 10;
        reverso = (reverso * 10) + digito;
        num = num / 10;
    }

    if (x == reverso) {
        return 1;
    }
    else {
        return 0;
    }
}
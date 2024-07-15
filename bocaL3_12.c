#include <stdio.h>

int somadosdigitos(int n);
void parImpar(int n);
void valorPrimo(int n);

int main(){

    int num;
    int digito;
    
    scanf("%d", &num);
    scanf("%*c");

    while (1) {

        num = somadosdigitos(num);

        printf("%d ", num);

        parImpar(num);
        valorPrimo(num);
        printf("\n");

        if (num < 10) {
            break;
        }
    }
return 0;
}

int somadosdigitos(int n) {

    int digito;
    int soma = 0;

    while (n != 0) {

        digito = n % 10;
        soma = soma + digito;
        n = n / 10;
    }

return soma;
}

void parImpar(int n) {
    if (n % 2 == 0) {
        printf("Par ");
    }
    else {
        printf("Impar ");
    }
}

void valorPrimo (int n) {

    int den = 1;
    int cont = 0;

    for (den; den <= n; den++) {

        if (n % den == 0) {
            cont++;
        }
    }
    if (cont == 2) {
        printf("Primo");
    }
    else {
        printf("Nao e primo");
    }
}
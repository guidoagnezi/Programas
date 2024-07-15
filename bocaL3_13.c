#include <stdio.h>

int CalculaValorPalavra();

int EhPrimo(int n);
int ProximoPrimo(int n);

int main(){

    int soma;

while (1) {

    soma = CalculaValorPalavra();
    
    if (soma == 0) {
        break;
    }

    if (EhPrimo(soma)) {
        printf("E primo\n");
    }
    else {
        printf("Nao e primo %d\n", ProximoPrimo(soma));
    }
}

return 0;
}

int CalculaValorPalavra() {

    char c;
    int soma = 0;

    while (scanf("%c", &c) == 1) {

        if (c >= 'a' && c <= 'z') {
            soma = soma + (c - 96);
        }
        else if (c >= 'A' && c <= 'Z') {
            soma = soma + (c - 38);
        }
        else if (c == '\n') {
            break;
        }
    }

    return soma;
}

int EhPrimo(int n) {

    int den = 1;
    int cont = 0;

    for (den; den <= n; den++) {

        if (n % den == 0) {
            cont++;
        }
    }

    if (cont == 2) {
        return 1;
    }

return 0;
}

int ProximoPrimo(int n) {

int den = 1;
int cont = 0;
    for (n++; n; n++) {

        den = 1;
        cont = 0;

        for (den; den <= n; den++) {

            if (n % den == 0) {
            cont++;
        }
        }

        if (cont == 2) {
            return n;
        }
    }
}

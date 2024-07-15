#include <stdio.h>

int EhPar (int n);
void PrintaPar(int n);
void PrintaImpar (int n);

int main (){

    int modo, n = 1, partida;


    scanf("%d %d", &modo, &partida);

    for (n; n <= partida * 2; n++) {

        if (modo == 0) {
            PrintaPar(n);
        }

        else if (modo == 1) {
            PrintaImpar(n);
            }
    }
return 0;
}

int EhPar(int n) {
    if (n % 2 == 0) {
        return 1;
    }
    else {
        return 0;
    }
}

void PrintaPar(int n) {
    if (EhPar(n)) {
        printf("%d ", n);
}
}

void PrintaImpar(int n) {
    if (!EhPar(n)) {
        printf("%d ", n);
    }
}

#include <stdio.h>

int main (){

    int x; //numeros
    int nx; //algarismo centena
    int menor = 1000000; //comparacao
    int cont0 = 0; //nenhum
    int num; //numeeerr o!
    int i;

for (i = 1; i <= 3; i++){

    scanf("%d", &x);

        if (x < 100) {
            cont0++;
            continue;
        }

    nx = (x % 1000) / 100;

    if (nx < menor) {
        menor = nx;
        num = i;
    }
    }

if (cont0 == 3) {
    printf("Nenhum");
}
else {
printf ("N%d", num);
}
}

#include <stdio.h>
#include <math.h>

int main (){
    int x, potencia;
    double soma1 = 0, soma2 = 0, soma3 = 0, num1, den1, den2, num3;
    scanf("%d", &x);

if (x == 1) {
        for (num1 = 1, den1 = 1; (num1 <= 99) && (den1 <= 50); num1+=2, den1++) {
            soma1 += (num1 / den1);
        }
    printf ("%f", soma1);
    }
if (x == 2) {
        for (den2 = 50, potencia = 1; (potencia <= 50) && (den2 >= 1); potencia++, den2-- ) {
            soma2 += pow(2, potencia) / den2;
        }
    printf("%f", soma2);
}
if (x == 3) {
    for (num3 = 1; num3 <= 10; num3++) {
        soma3 += num3 / pow(num3, 2);
    }
    printf ("%f", soma3);
}
return 0;
}
#include <stdio.h>
#include <math.h>   


int main(){

    float a, b, c, d;
    int x, y;
    double resultado, resultado2, resultado3;
    int pico = 0, vale = 0;

    scanf("%f %f %f %f %d %d", &a, &b, &c, &d, &x, &y);

    for (x; x <= y; x++) {
    
    resultado = (a * pow(x, 3) + b * pow(x, 2) + c * x + d);
    resultado2 = (a * pow(x-1, 3) + (b * pow(x-1, 2)) + c * (x-1) + d);
    resultado3 = (a * pow(x+1, 3) + (b * pow(x+1, 2)) + c * (x+1) + d);

        if (resultado > resultado2 && resultado > resultado3) {
            printf("Pico em x=%d\n", x);
            pico = 1;
        }

        else if (resultado < resultado2 && resultado < resultado3) {
            printf("Vale em x=%d\n", x);
            vale = 1;
        }
    }

if (!pico) {
    printf("Nao ha pico\n");
}
if (!vale) {
    printf("Nao ha vale\n");
}

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main(){

    float x, y; //atribuição dos lados do retangulo
    scanf("%f %f", &x, &y);

    float z = 2 * (x + y); //calculo do perimetro
    printf("%.2f\n", z);

return 0;

}
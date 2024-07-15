#include <stdio.h>
#include <math.h>

int main (){

    float x, y;
    scanf("%f %f", &x, &y);

    float z = (x + y) / 2;

    if (z >= 7) {
    printf("%.1f - Aprovado", z);
    }
    if (5 <= z && z < 7) {
    printf("%.1f - De Recuperacao", z);
    }
    if (5 > z) {
    printf("%.1f - Reprovado", z);
    }

return 0;
}
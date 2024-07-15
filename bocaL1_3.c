#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    float x, y, a, b;
    scanf("%f %f %f %f", &x, &y, &a, &b);


    float perimetro = 2 * (fabs(x - a) + fabs(y - b));
    printf("%.2f", perimetro);

    return 0;
}

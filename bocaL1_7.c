#include <stdio.h>
#include <math.h>

int main (){

    float x;
    char unidade;
    scanf("%f %c", &x, &unidade);

if ((unidade=='c') || (unidade=='C')) { //caso seja uma temperatura em celsius
    float z = x * (9.0 / 5.0) + 32.0;
    printf("%.2f (F)", z);

}
if ((unidade=='f') || (unidade=='F')) { //caso seja uma temperatura em farenheit
    float y = (5.0 * (x - 32.0)) / 9;
    printf("%.2f (C)", y);

}
return 0;
}
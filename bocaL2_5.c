#include <stdio.h>
#include <math.h>

int main (){
    float pi, k, soma = 0, final;
    int n;
    scanf("%d", &n);
    
    for (k = 1; k <= n; k++) {
        pi = 6 / pow(k, 2);
        soma += pi;
        final = sqrt(soma);
    }
    printf("%.6f", final);
return 0;
}
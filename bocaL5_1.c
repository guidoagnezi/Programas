#include <stdio.h>
#include <math.h>

int main(){

    int n, i = 0, ma, me, repr = 0, acim = 0;
    int nota, menor = 9999, maior = -9999;
    float dsv = 0, media = 0;

    scanf("%d", &n);
    scanf("%*c");

    int notas[n];

    for (i = 0; i < n; i++) {

        scanf("%d", &nota);
        scanf("%*c");

        notas[i] = nota;

        if (nota < menor) {
            menor = nota;
            me = i;
        }

        else if (nota > maior) {
            maior = nota;
            ma = i;
        }

        if (nota < 70) {
        repr++;
        }

        media = media + nota;

    }

    i = 0;

    for (i = 0; i < n; i++) {

        if (notas[i] > (media / n)){
            acim++;
        }

        dsv = dsv + pow(notas[i] - media / n, 2);

    }

    printf("MENOR:%d, MAIOR:%d, MEDIA:%.2f, STD:%.2f, ACIMA_MEDIA_CONC:%d, REPROV:%d\n", notas[me], notas[ma], media / n, sqrt(dsv / n), acim, repr);

return 0;
}
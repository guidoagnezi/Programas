#include <stdio.h>
#include <stdlib.h>

int main(){

    int qtdn, num, i = 1;
    int contp = 0, conti = 0;
    int pnum = 0;

    scanf("%d", &qtdn);

    for (i = 1; i <= qtdn; i++) {
        scanf("%*c");
        scanf("%d", &num);

        if (pnum == 0) {
            if (num % 2 != 0) {
                pnum = 1;
            }
            if (num % 2 == 0) {
                pnum = 2;
            }
        }

    if (num % 2 != 0) {
        conti++;
    }
    if (num % 2 == 0) {
        contp++;
    }
    }

    if (pnum == 1) {
        printf("QTD IMPARES:%d", conti);
    }
    if (pnum == 2) {
        printf("QTD PARES:%d", contp);
    }

return 0;
}

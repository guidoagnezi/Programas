#include <stdio.h>

int main(){

    int n1, n2, i = 0, i2 = 0;
    int cont = 0;

    scanf("%d", &n1);
    scanf("%*c");

    int a[n1];

    for (i = 0; i < n1; i++) {

        scanf("%d", &a[i]);

    }

    scanf("%d", &n2);
    scanf("%*c");

    int b[n2];


    for (i = 0; i < n2; i++) {
        
        scanf("%d", &b[i]);

    }

    for (i = 0; i < n1; i++) {

        for (i2 = 0; i2 < n2; i2++) {
        
        if (a[i] == b[i2]) {
                cont++;
                break;

            }
        }
    }

    if (cont == 0) {
        printf("NENHUM");
    }

    else if (cont == n1) {
        printf("TODOS");
    }

    else {
        printf("PARCIAL");
    }
return 0;
}
#include <stdio.h>

int main(){

    int n, i = 0;
    int num, pos;
    int existe = 0;
    
    scanf("%d %d", &num, &n);
    scanf("%*c");

    int numero[n];

    for (i = 0; i < n; i++) {

        scanf("%d", &numero[i]);

        if (numero[i] == num && !existe) {
            existe = 1;
            pos = i;
        }
    }

    if (existe) {
        printf("RESP:%d", pos);
    }
    else {
        printf("RESP:%d", n);
    }
}
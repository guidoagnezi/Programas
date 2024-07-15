#include <stdio.h>

int main(){

    int n, i = 0;
    int difftrue, razao;
    int cont = 0;

    scanf("%d", &n);
    scanf("%*c");

    int numero[n];

    for (i = 0; i < n; i++) {

        scanf("%d", &numero[i]);

        if (i == 1) {

            razao = numero[i] - numero[i - 1];
            
        }

        if (i > 0) {

            if (numero[i] - numero[i - 1] == razao) {

                cont++;
            }
        }

    }
    
    if (n <= 1) {
        printf("NAO");
    }

    else if (cont == n - 1) {
        printf("RESP:%d", razao);
    }
    
    else {
        printf("NAO");
    }
}
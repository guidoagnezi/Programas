#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    int n, i = 0;
    int altura;
    int diff = 0;
    int cont = 0;

    scanf("%d", &n);
    scanf("%*c");

    int postes[n];

    for (i = 0; i < n; i++) {

        scanf("%d", &altura);
        scanf("%*c");

        postes[i] = altura;

        if (i > 0) {
            
            cont++;
            if (abs(postes[i] - postes[i - 1]) > diff) {

                diff = abs(postes[i] - postes[i - 1]);

            }
        }
    }

    if (cont == 0) {
        printf("IMPOSSIVEL");   
    }

    else{

    for (i = 0; i < n; i++) {

        if (i > 0) {
        if (abs(postes[i] - postes[i - 1]) == diff) {

            printf(" (%d %d)", i - 1, i);
        }
        }
    
    }
    }
return 0;
}
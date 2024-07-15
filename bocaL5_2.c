#include <stdio.h>


int main(){

    int n, i = 0;
    int num, num2 = -1;
    int cres = 0, decres = 0, eq = 0;
    
    scanf("%d", &n);
    scanf("%*c");

    int notas[n];

    for (i; i < n; i++) {

        scanf("%d", &num);

        notas[i] = num;

        if (i > 0) {

            if (notas[i] < notas[i - 1]) {
                decres++;
            }
            if (notas[i] > notas[i - 1]) {
                cres++;
            }
            if (notas[i] == notas[i - 1]) {
                eq++;
            }
        }
    }

        if (n > 1) {

        if (cres == n - 1) {

            printf("CRESCENTE");
        } 

        else if (decres == n - 1) {

            printf("DECRESCENTE");
        }

        else if (eq == n - 1) {

            printf("CRESCENTE&DECRESCENTE");
        }

        else {
            
            printf("DESORDENADO");
        }

        }
        else {

            printf("CRESCENTE&DECRESCENTE");
        }
   
return 0;
}
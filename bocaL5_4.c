#include <stdio.h>

int main(){

    int n, i = 0;
    int x, y;
    int contd = 0, conta = 0;

    scanf("%d", &n);
    scanf("%*c");

    int numeros[n];

    for (i = 0; i < n; i++) {

        scanf("%d", &numeros[i]);
        scanf("%*c");
    }

    scanf("%d %d", &x, &y);

    for (i = 0; i < n; i++) {

        if (numeros[i] >= x && numeros[i] <= y) {
            contd++;
        }
        else {
            conta++;
        }
    }

    printf("%d %d", contd, conta);
}
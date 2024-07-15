#include <stdio.h>

int main(){
    int x, menor = 9999, cont = -1, cont1 = 0, cont2 = 0, contMaior = -99999, contMenor = 99999;
    char c, a;

    while (scanf("%d", &x) == 1) {
        if (x < menor) {
            menor = x;
        }
    }
    scanf("%*c");

    while (scanf("%d", &x) == 1){

        cont++;
        if (x == menor) {
            cont1 = cont;
            cont2 = cont;
            if (cont1 < contMenor) {
                contMenor = cont1;
            }
            if (cont2 > contMaior) {
                contMaior = cont2;
            }
        }
        }

if (cont1 == 0) {
    cont++;
    printf("%d %d %d", menor, cont, cont);
    }
if (cont1 != 0) {
    printf ("%d %d %d", menor, contMenor, contMaior);
}
return 0;
}
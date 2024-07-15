#include <stdio.h> 

int main (){
    int x, cont = 0, den;
    scanf ("%d", &x);

    for (den = 1; den <= x; den++) {
        if (x % den == 0) {
            cont++;
        }
    }
    if (cont == 2) {
        printf ("Primo");
    }
    else {
        printf ("Nao primo");
    }
return 0;
}
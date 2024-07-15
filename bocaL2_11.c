#include <stdio.h>

int main(){
    int x, y, rad, des, num, soma;
    scanf("%d %d", &x, &y);
        for (x++; x < y; x++) {
            rad = x / 100;
            des = x % 100;
            soma = des + rad;
        if ((soma * soma) == x) {
            printf ("%d\n", x);
        }
        }
return 0;
}
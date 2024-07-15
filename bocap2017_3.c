#include <stdio.h>

int main(){

    char a, b, c, d;

    scanf("%c%c %c%c", &a, &b, &c, &d);

    if  ((a < '0' || (a > '9' && a < 'A') || (a > 'Z' && a < 'a') || a > 'z')||(b < '0' || (b > '9' && b < 'A') || (b > 'Z' && b < 'a') || b > 'z') || (c < '0' || (c > '9' && c < 'A') || (c > 'Z' && c < 'a') || c > 'z') || (d < '0' || (d > '9' && d < 'A') || (d > 'Z' && d < 'a') || d > 'z')) {
        printf("Invalido");
    }

    else {

        if (a >= 'A' && a <= 'Z') {
            a+= 32;
        }
        if (b >= 'A' && b <= 'Z') {
            b+= 32;
        }
        if (c >= 'A' && c <= 'Z') {
            c+= 32;
        }
        if (d >= 'A' && d <= 'Z') {
            d+= 32;
        }

        if (a == c && b == d) {
            printf("IGUAIS");
        }
        else {
            printf("DIFERENTES");
        }
    }
return 0;
}
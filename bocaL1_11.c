#include <stdio.h>
#include <math.h>

int main (){
    int a;
    scanf("%d", &a);

if (a == 1) { // atribuição do numero ao mes 
    printf("Jan.\n");
}

if (a == 2) {
    printf("Fev.\n");
}

if (a == 3) {
    printf("Mar.\n");
}

if (a == 4) { 
    printf("Abr.\n");
}

if (a == 5) {
    printf("Mai.\n");
}

if (a == 6) {
    printf("Jun.\n");
}

if (a == 7) {
    printf("Jul.\n");
}

if (a == 8) {
    printf("Ago.\n");
}

if (a == 9) {
    printf("Set.\n");
}

if (a == 10) {
    printf("Out.\n");
}

if (a == 11) {
    printf("Nov.\n");
}

if (a == 12) {
    printf("Dez.\n");
}

if ((a != 1) && (a != 2) && (a != 3) && (a != 4) && (a != 5) && (a != 6) && 
(a != 7) && (a != 8) && (a != 9) && (a != 10) && (a != 11) && (a != 12)) { //expressao de invalido (reduzido)
    printf("Invalido.\n");
}
return 0;
}
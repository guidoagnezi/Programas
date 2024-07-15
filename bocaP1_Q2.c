#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
    int a, b, x1, y1, x2, y2, x3, y3;
    scanf("%d %d %d %d %d %d %d %d", 
    &a, &b, &x1, &y1, &x2, &y2, &x3, &y3);
if ((a * x1 + b == y1) && (a * x2 + b == y2) && (a * x3 + b == y3)) {
    printf("Todos");
}
if ((a * x1 + b == y1) == false && (a * x2 + b == y2) == false && (a * x3 + b == y3) == false) {
    printf("Nenhum");
}
if ((a * x1 + b == y1) && (a * x2 + b == y2) == false && (a * x3 + b == y3) == false) {
    printf("Um");
}
if ((a * x1 + b == y1) == false && (a * x2 + b == y2) == false && (a * x3 + b == y3)) {
    printf("Um");
}
if ((a * x1 + b == y1) == false && (a * x2 + b == y2) && (a * x3 + b == y3) == false) {
    printf("Um");
}
if ((a * x1 + b == y1) == false && (a * x2 + b == y2) && (a * x3 + b == y3)) {
    printf("Dois");
}
if ((a * x1 + b == y1) && (a * x2 + b == y2) == false && (a * x3 + b == y3)) {
    printf("Dois");
}
if ((a * x1 + b == y1) && (a * x2 + b == y2) && (a * x3 + b == y3) == false) {
    printf("Dois");
}
return 0;
}

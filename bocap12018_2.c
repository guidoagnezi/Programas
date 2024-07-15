#include <stdio.h>
#include <math.h>

int main (){
    int x, y;
    scanf("%d %d", &x, &y);
    int z = x / 5;
    int a = x % 5;
    int b = y / 5;
    int c = y % 5;
    
 if ((z + a) > (b + c)) {
    printf("QTD troco 1 eh maior!");
 }
 if ((z + a) < (b + c)) {
    printf("QTD troco 2 eh maior!");
}
 if ((z + a) == (b + c)) {
    printf("Iguais!");
 }
 return 0;
}

#include <stdio.h>
#include <math.h>

int main(){

    int x, y;
    scanf("%d %d", &x, &y);
    if (x > y) {
    printf("N1 = %d", x);
    }
    if (x < y) {
    printf("N2 = %d", y);
    }
    if (x == y) {
    printf("N1 = N2");
    }

return 0;

}
#include <stdio.h>
#include <math.h>

int main(){
    int x, y;
    scanf("%d %d", &x, &y);

if (y == 1) {
    int z = x % 10;
    if (z % 2 == 0) {
        printf("Par");
    }
    if (z % 2 != 0) {
    printf("Impar");
    }
}
if (y == 2) {
    int z = x / 10;
    if (z % 2 == 0) {
        printf("Par");
    }
    if (z % 2 != 0) {
    printf("Impar");
    }
}
if (y == 3) {
    int z = x / 100;
    if (z % 2 == 0) {
        printf("Par");
    }
    if (z % 2 != 0) {
    printf("Impar");
    }
}
return 0;
}
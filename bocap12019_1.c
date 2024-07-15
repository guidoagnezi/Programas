#include <stdio.h>
#include <math.h>

int main(){
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);

if (x > y && y > z) {
    printf("DECRESCENTE");
}
else if (z > y && y > x) {
    printf("CRESCENTE");
}
else {
    printf("TUDO DOIDO");
}
return 0;
}
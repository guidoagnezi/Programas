#include <stdio.h>
#include <math.h>

int main (){

    int x, y; //x eh o resto, y eh o numero
    scanf("%d", &y);
    x = y % 2;
if (x == 0) {
    printf("Par");
}
else {
    printf("Impar");
}
return 0;
}

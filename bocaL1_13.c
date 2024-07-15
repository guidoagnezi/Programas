#include <stdio.h>
#include <math.h>

int main(){
    int x, y; //x = pessoas y = itens
    scanf("%d %d", &x, &y);

if ((y % x) == 0) {
    printf("RESP:%d", x);
}
if ((y % x) != 0) {
    int z = y % x;
    printf("RESP:%d", z);
}
return 0;
}
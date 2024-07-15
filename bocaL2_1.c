#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
    int x, y;
    scanf("%d %d", &x, &y);
    printf("RESP:");
    for(x += 1; x < y; x++) {
        if (x % 2 == 0) {
            printf("%d ", x);
        }
}
    return 0;
}
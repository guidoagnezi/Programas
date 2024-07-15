#include <stdio.h>

int main(){
    int x, y, multi, produto;
    scanf("%d %d", &x, &y);

    for (x; x <= y; x++) {
        for (multi = 1; multi <= 10; multi++) {
            produto = x * multi;
            printf("%d x %d = %d\n", x, multi, produto);
        }
    }
return 0;
}
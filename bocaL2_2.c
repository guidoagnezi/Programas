#include <stdio.h>

int main (){
    int x, y;
    scanf("%d %d", &x, &y);

for (x += 1; x < y; x++) {
    if (x % 3 == 0 || x % 4 == 0 || x % 7 == 0) {
        printf ("%d ", x);
    }
}
return 0;
}
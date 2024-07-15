#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
    int a, b, c, d, e, f;
    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
if (e < a && e > c && f < b && f > d) {
    printf("Dentro");
}    
else if (e > a && e < c && f > b && f < d) {
    printf("Dentro");
}
else if (e < a && e > c && f > b && f < d) {
    printf("Dentro");
}
else if (e > a && e < c && f < b && f > d) {
    printf("Dentro");
}
else {
    printf("Fora");
}
return 0;
}
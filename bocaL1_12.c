#include <stdio.h>
#include <math.h>

int main(){
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);

if (x > y && y > z) {
    printf("N3 = %d, N2 = %d, N1 = %d", z, y, x);
}
if (x > z && z > y) {
    printf("N2 = %d, N3 = %d, N1 = %d", y, z, x);
}
if (z > y && y > x) {
    printf("N1 = %d, N2 = %d, N3 = %d", x, y, z);
}
if (z > x && x > y) {
    printf("N2 = %d, N1 = %d, N3 = %d", y, x, z);
}
if (y > x && x > z) {
    printf("N3 = %d, N1 = %d, N2 = %d", z, x, y);
}
if (y > z && z > x) {
    printf("N1 = %d, N3 = %d, N2 = %d", x, z, y);
}
return 0;

}
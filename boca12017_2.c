#include <stdio.h>
#include <math.h>

int main(){
    int x, y;
    scanf("%d %d", &x, &y);

if ((x >= 1 && x <= 5) && (y == x)) {
    printf("Um homem");
}
else if ((x > 0 && x <= 5) && (y != x) && (y > 0 && y <= 5)) {
    printf ("Par de homens");
}
else if ((x >= 6 && x <= 10) && (x == y)) {
    printf ("Uma mulher");
}
else if ((x >= 6 && x <= 10) && (y != x) && (y >= 6 && y <= 10)) {
    printf ("Par de mulheres");
} 
else if ((x >= 1 && x <= 5) && (y != x) && (y >= 6 && y <= 10)) {
    printf ("Um casal");
}
else if ((x >= 6 && x <= 10) && (y != x) && (y > 0 && y <= 5)) {
    printf("Um casal");
}
else {
    printf("Invalido");
}
return 0;
}
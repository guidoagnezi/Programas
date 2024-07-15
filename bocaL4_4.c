#include <stdio.h>

typedef struct {

    int x;
    int y;
} coord;

coord Simetrico(coord c);
int Quadrante (coord c);
void Apresentacao (coord c);

int main(){

    int n, i = 1;
    coord c;
    coord cs;

    scanf("%d", &n);
    scanf("%*c");

    for (i; i <= n; i++){

        scanf("%d %d", &c.x, &c.y);

        cs = Simetrico(c);
        
        Apresentacao(c);
        Apresentacao(cs);
        printf("\n");

    }
return 0;
}

coord Simetrico(coord c) {

    c.x = -c.x;
    c.y = -c.y;

    return c;
}

int Quadrante(coord c) {

    if (c.x > 0 && c.y > 0) {
        return 1;
    }

    if (c.x < 0 && c.y > 0) {
        return 2;
    }

    if (c.x < 0 && c.y < 0) {
        return 3;
    }

    if (c.x > 0 && c.y < 0) {
        return 4;
    }

    if (c.x == 0 || c.y == 0) {
        return 0;
    }
}

void Apresentacao (coord c){

printf("(%d,%d) %d ", c.x, c.y, Quadrante(c));

}
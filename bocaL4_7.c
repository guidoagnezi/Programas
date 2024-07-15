#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {

    int x1;
    int y1;
    int x2;
    int y2;
} tReta;

int Quadrante (int x, int y);

int main(){

    tReta r;
    int n, i = 1;
    int quad1, quad2;

        scanf("%d", &n);

        for (i; i <= n; i++) {
        
            scanf("%d %d %d %d", &r.x1, &r.y1, &r.x2, &r.y2);
            
            quad1 = Quadrante(r.x1, r.y1);
            quad2 = Quadrante(r.x2, r.y2);


            if (quad1 == 0 && quad2 == 0) {
                printf("DIFERENTE\n");
            }

            else if (quad1 == quad2) {
                printf("MESMO\n");
            }
            
            else {
                printf("DIFERENTE\n");
            }
        }
return 0;
}

int Quadrante (int x, int y){

    if (x > 0 && y > 0) {
        return 1;
    }

    if (x < 0 && y > 0) {
        return 2;
    }

    if (x < 0 && y < 0) {
        return 3;
    }

    if (x > 0 && y < 0) {
        return 4;
    }

    if (x == 0 || y == 0) {
        return 0;
    }
}

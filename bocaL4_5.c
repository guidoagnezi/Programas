#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {

    int x;
    int y;

} tPonto;

float CalculaDistancia(tPonto p, tPonto p2);

int main(){

    int n, i = 1;
    float dist;
    tPonto p;
    tPonto p2 = {0, 0};

    scanf("%d", &n);
    scanf("%*c");

    for (i; i <= n; i++) {

        scanf("%d %d", &p.x, &p.y);

        dist = CalculaDistancia(p, p2);

        if (i == 1) {
            printf("-\n");
        }

        else {
            printf("%.2f\n", dist);
        }

        p2 = p;

    }
return 0;
}

float CalculaDistancia(tPonto p, tPonto p2) {

    return sqrt(pow(abs(p.x - p2.x), 2) + pow(abs(p.y - p2.y), 2));
}

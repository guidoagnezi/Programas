#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {

    int x;
    int y;

} tPonto;

typedef struct {

    int x1;
    int y1;
    int x2;
    int y2;
} tReta;

float CalculaReta(tReta r);
float DistanciaPontoInicio(tPonto p, tReta r);
float DistanciaPontoFinal(tPonto p, tReta r);

int main(){

    int n, i = 1;
    tPonto p;
    tReta r;
    float dist1, dist2, reta;

    scanf("%d", &n);
    scanf("%*c");

    for (i; i <= n; i++) {

        scanf("%d %d %d %d %d %d", &p.x, &p.y, &r.x1, &r.y1, &r.x2, &r.y2);

        reta = CalculaReta(r);
        dist1 = DistanciaPontoInicio(p, r);
        dist2 = DistanciaPontoFinal(p, r);

        
        if (dist1 < dist2) {
            printf("INICIO\n");
        }
        else if (dist1 > dist2) {
            printf("FIM\n");
        }
        else {
            printf("EQUIDISTANTE\n");
        }
    }
return 0;
}


float CalculaReta(tReta r) {

    return sqrt(pow(abs(r.x1 - r.x2), 2) + pow(abs(r.y1 - r.y2), 2));
}

float DistanciaPontoInicio(tPonto p, tReta r) {

    return sqrt(pow(abs(r.x1 - p.x), 2) + pow(abs(r.y1 - p.y), 2));

}

float DistanciaPontoFinal(tPonto p, tReta r) {

    return sqrt(pow(abs(r.x2 - p.x), 2) + pow(abs(r.y2 - p.y), 2));

}
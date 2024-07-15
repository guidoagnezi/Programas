#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

int area_total (int r1_x1, int r1_y1, int r1_x2, int r1_y2, int r2_x1, int r2_y1, int r2_x2, int r2_y2);

int main(){

    int r1x, r1y, r1x2, r1y2, r2x, r2y, r2x2, r2y2;
    int area;

    scanf("%d %d %d %d", &r1x, &r1y, &r1x2, &r1y2);
    scanf("%d %d %d %d", &r2x, &r2y, &r2x2, &r2y2);

    area = area_total(r1x, r1y, r1x2, r1y2, r2x, r2y, r2x2, r2y2);

    printf("RESP:%d", area);

return 0;
}

int area_total (int r1_x1, int r1_y1, int r1_x2, int r1_y2, int r2_x1, int r2_y1, int r2_x2, int r2_y2) {

    int alt1 = abs(r1_y1 - r1_y2), com1 = abs(r1_x1 - r1_x2), alt2 = abs(r2_y1 - r2_y2), com2 = abs(r2_x1 - r2_x2);

    int xsobreposto = max(0, min(r1_x2, r2_x2) - max(r1_x1, r2_x1));
    int ysobreposto = max(0, min(r1_y2, r2_y2) - max(r1_y1, r2_y1));
    int area_inter = xsobreposto * ysobreposto;

    return ((alt1 * com1) + (alt2 * com2)) - area_inter;

}

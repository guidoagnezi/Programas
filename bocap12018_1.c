#include <stdio.h>
#include <math.h>

int main (){
    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

if (x2 > x1 && y2 > y1) { //x2 e y2 eh canto superior direito ex 1 1 2 2
    printf ("(%d,%d)(%d,%d)(%d,%d)(%d,%d)", x1, y2, x1, y1, x2, y1, x2, y2);
} 
if (x1 > x2 && y1 > y2) { //x1 e y1 eh canto superior direito 2 2 1 1
    printf ("(%d,%d)(%d,%d)(%d,%d)(%d,%d)", x2, y1, x2, y2, x1, y2, x1, y1);
}
if (x1 < x2 && y1 > y2) { // x2 e y2 sao canto inferior direito 1 2 2 1
    printf("(%d,%d)(%d,%d)(%d,%d)(%d,%d)", x1, y1, x1, y2, x2, y2, x2, y1);
}
if (x1 > x2 && y1 < y2) { //x1 e y1 sao canto inferior direito 2 1 1 2
    printf("(%d,%d)(%d,%d)(%d,%d)(%d,%d)", x2, y2, x2, y1, x1, y1, x1, y2);
}

return 0;
}


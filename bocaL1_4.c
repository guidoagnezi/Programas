#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.141592

int main(){

    float x;
    scanf("%f", &x);

    float y = PI * pow(x, 2);
    

    float z = sqrt(y / (2 * PI));

    printf("%.2f %.2f", y, z);


return 0;
}
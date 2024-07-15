#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(){

	float x;
	float y;
	scanf("%f %f", &x, &y);
	
	float z = sqrt(x);
	float w = sqrt(y);
	float a = z + w;
	
	printf("%.2f", a);
	
return 0;

}

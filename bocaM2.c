#include <stdio.h>
#include <stdlib.h>

int main(){

	float x;
	scanf("%f", &x);
	
	//retirada da parte decimal
	int y = x;
	//retirada da parte inteira
	float z = (x - y);
	
	printf("INTEIRO:%d,REAL:%.2f\n", y, z);
	
return 0;
}
        

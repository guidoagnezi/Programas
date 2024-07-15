#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
int main(){
int x = 1, contP = 0, contN = 0, somaP = 0, somaN = 0;


    while(scanf("%d", &x) == 1) {      

    
    if (x < 0) {
        contN++;
        somaN += x;
    
    }
    if (x > 0) {
        contP++;
        somaP += x;
    }
    }
    
printf("%d %d %d %d", contN, contP, somaN, somaP);

return 0;
}
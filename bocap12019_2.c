#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main (){
    int x, y, z;
    char a;    
    scanf ("%d %c %d", &x, &a, &y);
    int w = x % y;

if (a == '+') {
    z = x + y;
    printf("SOMA:%d", z);    
}
else if (a == '-') {
    z = x - y;
    printf("SUB:%d", z);    
}
else if (a == '*') {
    z = x * y;
    printf("MULT:%d", z); 
}
else if ((a == '/') && (w == 0)) {
    z = x / y;
    printf("DIV:%d", z);
}
else if ((a == '/') && (w > 0)) {
    z = x / y;
    printf("DIV:%d, RESTO:%d", z, w);
}
return 0;
}
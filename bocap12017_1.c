#include <stdio.h>
#include <math.h>

int main (){
    int x, y, z;
    char a;
    scanf ("%d %d %c", &x, &y, &a);

if (a == '+') {
    z = x + y;
    printf("RESP:%d", z);    
}
else if (a == '-') {
    z = x - y;
    printf("RESP:%d", z);    
}
else if (a == '*') {
    z = x * y;
    printf("RESP:%d", z); 
}
else if (a == '/') {
    z = x / y;
    printf("RESP:%d", z);
}
else {
    printf("Invalido");
}
return 0;
}
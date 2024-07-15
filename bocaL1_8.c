#include <stdio.h>
#include <math.h>
 
 int main (){

    char letra;
    scanf("%c", &letra);

    if ((letra == 'a') || (letra == 'e') || (letra == 'i') || (letra == 'o') || (letra == 'u') || 
    (letra == 'A') || (letra == 'E') || (letra == 'I') || (letra == 'O') || (letra == 'U')) {
    printf("Vogal");
    }
    else {
    printf("Nao vogal");
    }
return 0;
 }
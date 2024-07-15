#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main(){
 char caractere;
 scanf("%c", &caractere);

 if (isupper(caractere)) {
    printf("A letra deve ser minuscula!");
 }

 if (isalpha(caractere) && islower(caractere)) {
    char caractere2 = toupper(caractere);
    printf("%c(%d)", caractere2, caractere2);
}

if (isalpha(caractere) == false) {
    printf("Nao e letra!");

}

 return 0;
}
#include <stdio.h>

int main(){
    int num, soma = 0, digito;

    scanf("%d", &num);
    printf("RESP:");
    
while (1) {
    soma = 0;
    while(num != 0) {

        digito = num % 10;
        num = num / 10;
        soma = soma + digito;

    }

    if (soma <= 9) {
        printf("%d", soma);
        break;
    }  
        num = soma;
}

    return 0;
}
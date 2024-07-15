#include <stdio.h>

int main(){

    int qtd, num, cont = 1, pos;
    int menorn = 999999;

    scanf("%d", &qtd);
    if (qtd == 0) {
    return 0;
}

    for (cont = 1; cont <= qtd; cont++) {
    
        scanf("%*c");
        scanf("%d", &num);

        if (num < menorn) {
            pos = cont;
            menorn = num;
        }
    }
printf("POS:%d", pos);
return 0;
}
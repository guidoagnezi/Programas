#include <stdio.h>

int main(){
int linhas, colunas, num, i, j, contJ, contL, maior = -999999;

scanf("%d %d", &linhas, &colunas);

for (i = 1; i <= linhas; i++) {
    for (j = 1; j <= colunas; j++) {
        scanf("%d", &num);
        if (num > maior) {
            maior = num;
            contL = i;
            contJ = j;
        }
    }
}
printf ("%d (%d, %d)", maior, contL, contJ);
return 0;
}
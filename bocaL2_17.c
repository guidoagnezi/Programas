#include <stdio.h>
#include <ctype.h>

int main(){
    int x, y, codificado, decodificado;
    char c;

    scanf ("%d %d", &x, &y);

    scanf ("%*c");
    if (x == 1) {

        while (1) {

        scanf("%c", &c);
        codificado = c;
        if (c == '.') {
                printf(".");
                break;
        }
        
        if (c >= 97 && c <= 122) {
        codificado = c + y;
            while (codificado > 122) {
                codificado = (codificado - 122) + 96;
            }
        }
        printf("%c", codificado);
    }
    }
    if (x == 2) {

        while (1) {

        scanf("%c", &c);
        decodificado = c;
            if (c == '.') {
                printf(".");
                break;
            }

        if (c >= 97 && c <= 122) {
        decodificado = c - y;
            while (decodificado < 97) {
                decodificado = (decodificado + 122) - 96;
            }
        

        }
        printf("%c", decodificado);
        }
    }
    if (x != 1 && x != 2) {
        printf ("Operacao invalida.");
    }

return 0;
}
    
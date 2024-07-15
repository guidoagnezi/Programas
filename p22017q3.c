#include <stdio.h>

int QtdDebitoPlaca (int presc);
int MaiorDebitoCidade ();


int main (){

int ncidades, soma = 0, maior, i = 1;

    scanf("%d", &ncidades);


    for (i = 1; i <= ncidades; i++) {
        maior = MaiorDebitoCidade();
        soma = soma + maior;
    }

    printf ("SOMA:%d", soma);

return 0;

}


int MaiorDebitoCidade(){

    int presc, maior = 0, debito = -1;
    char n1, n2, n3, abr;
    char p1, p2, p3;

    scanf("%d", &presc);

    while (1) {
        scanf("%*c");
        scanf("%c%c%c", &n1, &n2, &n3);

        if (n1 == 'F' && n2 == 'I' && n3 == 'M') {
            if (maior != 0) {
            printf("PLACA:%c%c%c DEBITO:%d\n", p1, p2, p3, maior);
            break;
            }
            if (maior == 0) {
            printf("SEM DEBITO!\n");
            break;
            }
        }

        else {

        debito = QtdDebitoPlaca(presc);

        }

        if (debito > maior) {
            maior = debito;
            p1 = n1, p2 = n2, p3 = n3;
        }
    }
    return maior;
} 

int QtdDebitoPlaca(int presc) {

int debito = -1, ano, somad = 0;
char par1, dp, par2;

while (scanf("(%d:%d)", &debito, &ano) == 2) {

        if (ano <= presc) {
            somad+= debito;
        }

}
    return somad;
}

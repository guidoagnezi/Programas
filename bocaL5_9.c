#include <stdio.h>

void ImprimeDadosDoVetor(int vet [], int qtd);
void InverteVetor(int * vet, int qtd);


int main(){

    int n, i = 0;
    
    scanf("%d", &n);
    scanf("%*c");

    int numero[n];

    for (i = 0; i < n; i++) {

        scanf("%d", &numero[i]);

    }

    InverteVetor(numero, n);
}

void InverteVetor(int * vet, int qtd) {

    int i = 0;
    int numero[qtd];

    for (i = 0; i < qtd; i++) {

        numero[i] = vet[(qtd - 1) - i];

    }

ImprimeDadosDoVetor(numero, qtd);

}

void ImprimeDadosDoVetor(int vet[], int qtd) {
    
    int i = 0;

    printf("{");

    for (i = 0; i < qtd; i++) {

        printf ("%d", vet[i]);
        if ( i != qtd - 1) {
            printf(", ");
        }
    }

    printf("}");
}
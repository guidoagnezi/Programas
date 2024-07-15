#include <stdio.h>

void TrocaParEImpar(int vet[], int qtd);
void ImprimeDadosDoVetor(int vet [], int qtd);

int main(){

    int n, i = 0;

    scanf("%d", &n);

    int numero[n];

    for (i = 0; i < n; i++) {

        scanf("%d", &numero[i]);
    }

    TrocaParEImpar(numero, n);
    
return 0;
}

void TrocaParEImpar (int vet[], int qtd) {

    int i = 0;
    int num;

    for (i = 0; i < qtd; i++) {

        if (i != qtd - 1){
        
        num = vet[i];
        vet[i] = vet[i + 1];
        vet[i + 1] = num;

        i++;
        }
    }

ImprimeDadosDoVetor(vet, qtd);
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
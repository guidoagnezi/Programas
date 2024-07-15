#include <stdio.h>

void ImprimeDadosDoVetor(int vet [], int qtd);
void OrdenaCrescente(int vet[], int qtd);


int main(){

    int n, i = 0;

    scanf("%d", &n);
    scanf("%*c");

    int vet[n];

    for (i; i < n; i++) {

        scanf("%d", &vet[i]);

    }

    OrdenaCrescente(vet, n);

}

void OrdenaCrescente(int vet[], int qtd) {

    int i = 0, j = 0, aux;

    for (i = 0; i < qtd; i++) {

        for (j = 0; j < qtd; j++) {

            if (vet[i] < vet[j]) { //troca de lugar
                
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;

            }
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
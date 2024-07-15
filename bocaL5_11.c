#include <stdio.h>

void ImprimeDadosDoVetor(int vet [], int qtd);
void OrdenaCrescente(int vet[], int qtd);


int main(){

    int n, n2, i = 0;

    scanf("%d", &n);
    scanf("%*c");

    int vet[n];

    for (i = 0; i < n; i++) {

        scanf("%d", &vet[i]);

    }

    scanf("%d", &n2);
    scanf("%*c");

    int vet2[n2];

    for (i = 0; i < n2; i++) {

        scanf("%d", &vet2[i]);

    }

    OrdenaCrescente(vet, n);
    OrdenaCrescente(vet2, n2);

    int p1 = 0, p2 = 0;

    while(p1 < n && p2 < n2) {

        if (vet[p1] <= vet2[p2]) {
            printf("A");
            p1++;
        }

        else {
            printf("B");
            p2++;
        }
    }

    while(p1 < n) {
        printf("A");
        p1++;
    }
    
    while(p2 < n2) {
        printf("B");
        p2++;
    }
return 0;
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
}

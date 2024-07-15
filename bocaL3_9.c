#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int verificapH(float pH);
int verificaGotaChuvaAcida(float pH);
float porcentagem(float total, float valor);
void imprimeResultadosAnalise(float porcentagemGotasChuvaAcida, float porcentagemGotasChuvaNormal);

int main(){

    int area, densidade, tempo;
    int i = 1;
    float pct1, pct2, ph, contacid = 0, gotas, valor = 0;
    int acido = 0, neutro = 0, basico = 0, pH;
    float macido = 99, mbasico = -1, mneutro = 99, mneutro1;

    scanf("%d %d %d", &area, &densidade, &tempo);

    gotas = area * densidade * tempo;

    if (gotas == 0) {
        printf("Nenhuma gota foi avaliada");
    }

    else {
    for (i = 1; i <= gotas; i++) {

        scanf("%f", &ph);

//contagem ph
        if (verificapH(ph) == 1) {
            neutro++;
        }
        else if (verificapH(ph) == 0) {
            acido++;
        }
        else if (verificapH(ph) == 2) {
            basico++;
        }


        if (ph < macido) {
            macido = ph;
        }
        if (ph > mbasico) {
            mbasico = ph;
        }
        if (fabs(ph - 7) < mneutro) {
            mneutro = fabs(ph - 7);
            mneutro1 = ph;
        }

        if (pH = verificaGotaChuvaAcida(ph)) {
            contacid++;
        }
        
    }

    printf("%d %d %d %.2f %.2f %.2f\n", acido, basico, neutro, macido, mbasico, mneutro1);

    pct1 = porcentagem(gotas, contacid);
    pct2 = 100 - pct1;

    imprimeResultadosAnalise(pct1, pct2);

    }
return 0;
}
int verificapH(float pH) {
    if (pH < 7.00) {
        return 0;
    }
    if (pH == 7.00) {
        return 1;
    }
    if (pH > 7.00) {
        return 2;
    }
}

int verificaGotaChuvaAcida(float pH) {
    if (pH < 5.70) {
        return 1;
    }
    else {
    return 0;
}
}

float porcentagem(float total, float valor) {

    float pct = (valor / total) * 100;
    return pct;
}

void imprimeResultadosAnalise(float porcentagemGotasChuvaAcida, float porcentagemGotasChuvaNormal) {

    if (porcentagemGotasChuvaAcida >= 75.00) {
        printf("Chuva Acida ");
    }
    else if (porcentagemGotasChuvaNormal >= 75) {
        printf("Chuva Normal ");
    }
    else {
        printf("Chuva com indicios de chuva acida ");
    }

    printf("%.2f%% %.2f%%", porcentagemGotasChuvaAcida, porcentagemGotasChuvaNormal);

}
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int codigo;
    char sobrenome[21];
    char nome[21];
    int nota;
    int idade;
    int jafoi;
} tCandidato;

tCandidato LeCandidato();

void ImprimeCandidato(tCandidato candidato);

int ComparaString(char *str1, char *str2);

int main()

{
    int qtdCand, i = 0;
    int i2 = 0, jafoi = 0;

    scanf("%d", &qtdCand);

    tCandidato candidatos[qtdCand];

    for (i = 0; i < qtdCand; i++)
    {
        candidatos[i] = LeCandidato();
        candidatos[i].jafoi = 0;

    }

    for(i = 0; i < qtdCand; i++){

        for (i2 = 0; i2 < qtdCand; i2++) {

            if (i2 == i) {
                continue;
            }

            if (ComparaString(candidatos[i].sobrenome, candidatos[i2].sobrenome)){

                if (!candidatos[i].jafoi) {
                    ImprimeCandidato(candidatos[i]);
                    candidatos[i].jafoi = 1;
                }

                if(!candidatos[i2].jafoi) {
                    ImprimeCandidato(candidatos[i2]);
                    candidatos[i2].jafoi = 1;
                }
            }
        }
    }
}

tCandidato LeCandidato()
{
    tCandidato candidato;
    scanf("%*[^{]");
    scanf("%*[{ ]");
    scanf("%d", &candidato.codigo);
    scanf("%*[, ]");
    scanf("%[^,],", candidato.sobrenome);
    scanf("%*[ ]");
    scanf("%[^,],", candidato.nome);
    scanf("%d", &candidato.nota);
    scanf("%*[, ]");
    scanf("%d", &candidato.idade);
    scanf("%*[^\n]");
    return candidato;
}

void ImprimeCandidato(tCandidato candidato)
{
    printf("CAND(%d): %s %s, Nota:%d, Idade:%d\n",
           candidato.codigo, candidato.nome,
           candidato.sobrenome, candidato.nota, candidato.idade);
}

int ComparaString(char *str1, char *str2) {

    int i = 0;
    int cont1 = 0;
    int cont2 = 0;
    int cont3 = 0;

    while (str1[i] != '\0'){
        cont1++;
        i++;
    }

    i = 0;

    while (str2[i] != '\0'){
        cont2++;
        i++;
    }

    if (cont1 != cont2) {
        return 0;
    }

    for(i = 0;(str1[i] != '\0' || str2[i] != '\0'); i++){

        if (str1[i] == str2[i]) {
            cont3++;
        }

    }

    return cont1 == cont3;
}
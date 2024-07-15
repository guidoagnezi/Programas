#include <stdio.h>

int main(){

    int ndel, del = 1;
    char genero; 
    int atleta, atleta2M = -1, atleta2F = -1;
    int nota1, nota2, nota3;
    int notaMaiorM = -1, nota2oM = -1, nota3oM = -1; //home
    int notaMaiorF = -1, nota2oF = -1, nota3oF = -1; //mule
    int melhorM, melhorF, piorM, piorF;
    int maiorM = -99999, maiorF = -99999, menorM = 99999, menorF = 99999; //comparacao
    int notaS = -1, notaT = -1, notaSF = -1, notaTF = -1;
    int notaSP = 9999, notaPSF = 9999, maiorFP = 99999, maiorMP = 99999;
    int somaM = 0, somaF = 0, somaF2 = 0, somaM2 = 0;
    int delM, delF, delM2 = 0, delF2 = 0;

    scanf("%d", &ndel);

    for (del; del <= ndel; del++) {

    atleta2M = -1, atleta2F = -1;
    notaMaiorM = -1, nota2oM = -1, nota3oM = -1; //home
    notaMaiorF = -1, nota2oF = -1, nota3oF = -1; //mule
    melhorM, melhorF, piorM, piorF;
    maiorM = -99999, maiorF = -99999, menorM = 99999, menorF = 99999; //comparacao
    notaS = -1, notaT = -1, notaSF = -1, notaTF = -1;
    notaSP = 9999, notaPSF = 9999, maiorFP = 99999, maiorMP = 99999;
    somaM = 0, somaF = 0;

        while (1) {
            scanf("%d", &atleta);
            if (atleta == -1) {
                break;
            }
            scanf(" %c", &genero);
            scanf(" %d %d %d", &nota1, &nota2, &nota3);
            if (genero == 'M') {
                if (nota1 >= nota2 && nota2 >= nota3){
                    notaMaiorM = nota1;
                    nota2oM = nota2;
                    nota3oM = nota3;
                }
                if (nota1 >= nota3 && nota3 >= nota2) {
                    notaMaiorM = nota1;
                    nota2oM = nota3;
                    nota3oM = nota2;
                    }
                if (nota2 >= nota1 && nota1 >= nota3){
                    notaMaiorM = nota2;
                    nota2oM = nota1;
                    nota3oM = nota3;
                }
                if (nota2 >= nota3 && nota3 >= nota1){
                    notaMaiorM = nota2;
                    nota2oM = nota3;
                    nota3oM = nota1;
                }
                if (nota3 >= nota2 && nota2 >= nota1){
                    notaMaiorM = nota3;
                    nota2oM = nota2;
                    nota3oM = nota1;
                }
                if (nota3 >= nota1 && nota1 >= nota2){
                    notaMaiorM = nota3;
                    nota2oM = nota1;
                    nota3oM = nota2;
                }
                //delegacao campea
                somaM+= notaMaiorM;
                
                //PARA MAIOOOOOOOOR
                if (notaMaiorM > maiorM) {
                    maiorM = notaMaiorM;
                    notaS = nota2oM;
                    notaT = nota3oM;
                    melhorM = atleta;
                }
                if (notaMaiorM == maiorM) {
                    if (nota2oM > notaS) {
                        melhorM = atleta;
                        maiorM = notaMaiorM;
                        notaS = nota2oM;
                        notaT = nota3oM;
                    }
                    if (nota2oM == notaS){
                        if (nota3oM > notaT) {
                           melhorM = atleta;
                            maiorM = notaMaiorM;
                            notaS = nota2oM;
                            notaT = nota3oM; 
                        }
                        if (nota3oM == notaT) {
                            if (atleta < melhorM) {
                                melhorM = atleta;
                                maiorM = notaMaiorM;
                                notaS = nota2oM;
                                notaT = nota3oM;
                                
                            }
                        }
                    }
                }
                //PARA PIOOOOOOOOOOOR
                if (notaMaiorM  < menorM) {
                    menorM = notaMaiorM;
                    notaSP = nota2oM;
                    maiorMP = nota3oM;
                    piorM = atleta;
                }
                if (notaMaiorM  == menorM) {
                    if (nota2oM < notaSP) { //notaSP
                        piorM = atleta;
                        menorM = notaMaiorM;
                        notaSP = nota2oM;
                        maiorMP = nota3oM;
                    }
                    if (nota2oM == notaSP){
                        if (nota3oM < maiorMP) { //maiorMP
                        piorM = atleta; 
                        menorM = notaMaiorM;
                        notaSP = nota2oM;
                        maiorMP = nota3oM;
                        }
                        if (nota3oM == maiorMP) {
                            if (atleta > piorM) {
                                piorM = atleta;
                                menorM = notaMaiorM;
                                notaSP = nota2oM;
                                maiorMP = nota3oM;
                            }
                        }
                    }
                }                

            
            }
            if (genero == 'F') {
                if (nota1 >= nota2 && nota2 >= nota3){
                    notaMaiorF = nota1;
                    nota2oF = nota2;
                    nota3oF = nota3;
                }
                if (nota1 >= nota3 && nota3 >= nota2) {
                    notaMaiorF = nota1;
                    nota2oF = nota3;
                    nota3oF = nota2;
                    }
                if (nota2 >= nota1 && nota1 >= nota3){
                    notaMaiorF = nota2;
                    nota2oF = nota1;
                    nota3oF = nota3;
                }
                if (nota2 >= nota3 && nota3 >= nota1){
                    notaMaiorF = nota2;
                    nota2oF = nota3;
                    nota3oF = nota1;
                }
                if (nota3 >= nota2 && nota2 >= nota1){
                    notaMaiorF = nota3;    delM, delF, delM2 = 0, delF2 = 0;
                    nota2oF = nota2;
                    nota3oF = nota1;
                }
                if (nota3 >= nota1 && nota1 >= nota2){
                    notaMaiorF = nota3;
                    nota2oF = nota1;
                    nota3oF = nota2;
                }
                //delegacao campea
                somaF+= notaMaiorF;

                //PARA MAIOOOOOOOOR
                if (notaMaiorF > maiorF) {
                    maiorF = notaMaiorF;
                    notaSF = nota2oF;
                    notaTF = nota3oF;
                    melhorF = atleta;
                }
                if (notaMaiorF == maiorF) {
                    if (nota2oF > notaSF) {
                    maiorF = notaMaiorF;
                    notaSF = nota2oF;
                    notaTF = nota3oF;
                        melhorF = atleta;
                    }
                    if (nota2oF == notaSF){
                        if (nota3oF > notaTF) {
                        maiorF = notaMaiorF;
                        notaSF = nota2oF;
                        notaTF = nota3oF;
                           melhorF = atleta; 
                        }
                        if (nota3oF == notaTF) {
                            if (atleta < melhorF) {
                            maiorF = notaMaiorF;
                            notaSF = nota2oF;
                            notaTF = nota3oF;
                                melhorF = atleta;
                            }
                        }
                    }
                }
                //PARA PIOOOOOOOOOOOR
                if (notaMaiorF < menorF) {
                    menorF = notaMaiorF;
                    notaPSF = nota2oF;
                    maiorFP = nota3oF;
                    piorF = atleta;
                }
                if (notaMaiorF == menorF) {
                    if (nota2oF < notaPSF) {
                    menorF = notaMaiorF;
                    notaPSF = nota2oF;
                    maiorFP = nota3oF;
                    piorF = atleta;
                    }
                    if (nota2oF == notaPSF){
                        if (nota3oF < maiorFP) {
                        menorF =  notaMaiorF;
                        notaPSF = nota2oF;
                        maiorFP = nota3oF;
                        piorF = atleta; 
                        }
                        if (nota3oF == maiorFP) {
                            if (atleta > piorF) {
                                piorF = atleta;
                                menorF =  notaMaiorF;
                                notaPSF = nota2oF;
                                maiorFP = nota3oF;
                            }
                        }
                    }
                }                

   
        }
    }

    if (somaM > somaM2) {
        delM = del;
        somaM2 = somaM;
    }
    if (somaM == somaM2) {
        if (del < delM) {
            delM = del;
        }
    }


    if (somaF > somaF2) {
        delF = del;
        somaF2 = somaF;
    }
    if (somaF == somaF2) {
        if (del < delF) {
            delF = del;
        }    delM, delF, delM2 = 0, delF2 = 0;
    }




    printf("MELHORES ATLETAS DA DELEGACAO %d\n", del);
    printf("MASCULINO: %d FEMININO: %d\n", melhorM, melhorF);
    printf("PIORES ATLETAS DA DELEGACAO %d\n", del);
    printf("MASCULINO: %d FEMININO: %d\n\n", piorM, piorF);
    }
    printf("DELEGACAO CAMPEA:\nMASCULINO: %d FEMININO: %d", delM, delF);
return 0;
}
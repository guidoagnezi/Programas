#include <stdio.h>

typedef struct {

    int d;
    int m;
    int a;

} data;

data VerData(data d);

int main(){

    data inicial;
    data final;

    scanf("%d %d %d", &inicial.d, &inicial.m, &inicial.a);
    scanf("%d %d %d", &final.d, &final.m, &final.a);

    inicial = VerData(inicial);
    final = VerData(final);
    for (inicial.d; 1 ; inicial.d++){

        if (inicial.d > 31 && (inicial.m == 1 || inicial.m == 3 || inicial.m == 5 || inicial.m == 7 || inicial.m == 8 || inicial.m == 10 || inicial.m == 12)) {
            inicial.m++;
            inicial.d = 1;
        }
        if (inicial.d > 30 && (inicial.m == 4 || inicial.m == 6 || inicial.m == 9 || inicial.m == 11)){
            inicial.m++;
            inicial.d = 1;
        }

        if (inicial.d > 28 && inicial.m == 2) {
            inicial.m++;
            inicial.d = 1;
        }

        if (inicial.m > 12) {
            inicial.a++;
            inicial.m = 01;
            inicial.d = 01;
        }

        if (inicial.d == final.d && inicial.m == final.m && inicial.a == final.a) {
            break;
        }

        printf("'%02d/%02d/%d'\n", inicial.d, inicial.m, inicial.a);
        } 
}

data VerData(data d){

    if (d.m > 12) {
        d.m = 12;
    }
    
    if (d.d > 30 && (d.m == 4 || d.m == 6 || d.m == 9 || d.m == 11)) {
        d.d = 30;
    }

    else if (d.d > 31 && (d.m == 1 || d.m == 3 || d.m == 5 || d.m == 7 || d.m == 8 || d.m == 10 || d.m == 12)) {
        d.d = 31;
    }

    else if (d.d > 28 && d.m == 2) {
        d.d = 28;
    }

    return d;
}

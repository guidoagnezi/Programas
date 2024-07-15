#include <stdio.h>

typedef struct {

    int d;
    int m;
    int a;

} data;

int VerBisexto (data d);
data VerData(data d);

int main(){

    int n, i = 1;
    data d;

    scanf("%d", &n);
    scanf("%*c");


    for (i; i <= n; i++) {

        scanf("%d %d %d", &d.d, &d.m, &d.a);

        d = VerData(d);

        if (VerBisexto (d)){

            printf("'%02d/%02d/%d':Bisexto\n", d.d, d.m, d.a);
        }
        else {

            printf("'%02d/%02d/%d':Normal\n", d.d, d.m, d.a);
        }

    }
return 0;
}

int VerBisexto (data d) {

if (d.a % 4 == 0) {
    return 1;
}

if (d.a % 400 == 0) {
    return 1;
}
return 0;
}



data VerData(data d){

    if (d.m > 12) {
        d.m = 12;
    }

    if (d.m < 1) {
        d.m = 1;
    }
    
    if (d.d < 1) {
        d.d = 1;
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
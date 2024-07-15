#include <stdio.h>

int Propriedade(int num);


int main (){

    int x, y, ver;
    scanf("%d %d", &x, &y);

    for (x+=1; x < y; x++) {

        ver = Propriedade(x);
        if (ver == 1) {
            printf("%d\n", x);
        }
    }

return 0;   
}

int Propriedade(int num) {

    int ab = num / 100;
    int cd = num  % 100;
    int ef = ab + cd;

    if (ef * ef == num) {
        return 1;
    }
    else {
        return 0;
    }
}
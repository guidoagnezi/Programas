#include <stdio.h>

int main(){

int conj;
int i = 1, num, n1, n2, n3, n4, n5, n6, n7, n8, n9;
char c;
int d;
int cona = 0;

    scanf("%d", &conj);
    scanf("%*c");
    
for (i; i <= conj; i++){

    scanf("%d", &num);

    switch (i) {
        case 1: n1 = num;
            break;
        case 2: n2 = num;
            break;
        case 3: n3 = num;
            break;
        case 4: n4 = num;
            break;
        case 5: n5 = num;
            break;
        case 6: n6 = num;
            break;
        case 7: n7 = num;
            break;
        case 8: n8 = num;
            break;
        case 9: n9 = num;
            break;
    }
}
scanf("%*c");

while (1) {
    
    scanf("%c", &c);

    if (c == '"') {
        cona++;

    if (cona == 2) {
        break;
    }
    }

    if (c != '"') {

        if (c != '%') {
            printf("%c", c);
        }
        if (c == '%') {

            scanf ("%d", &d);

            if (d >= i || d < 1) {
            printf("ERRO");
            }
            if (d < i && d >= 1) {
            
            switch (d) {

            case 1: d = n1;
                break;
            case 2: d = n2;
                break;
            case 3: d = n3;
                break;
            case 4: d = n4;
                break;
            case 5: d = n5;
                break;
            case 6: d = n6;
                break;
            case 7: d = n7;
                break;
            case 8: d = n8;
                break;
            case 9: d = n9;
                break;
            }
            printf("%d", d);
            }
            }
        }
        }
        
return 0;
    }



        




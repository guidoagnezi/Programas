#include <stdio.h>

int main(){
char c;
int resp = 1;
    for (1; 1; 1) {      
    c = c;
        scanf("%c", &c);
        

        if (c >= 97 && c <= 122) {
            c -= 32;
            printf("%c", c);
        }
        else if (c == '.' || c == '!' || c == '?') {
            printf("%c", c);
            break;
        }
        else {
            printf("%c", c);
        }

    }
return 0;
}
#include <stdio.h>

int main(){
char c;
int resp = 1;
    for (1; 1; 1) {      

        scanf("%c", &c);
        
        if (resp == 1) {
            printf("RESP:");
            resp++;
        }

        if (c == '.' || c == '!' || c == '?') {
            printf("%c", c);
            break;
        }
        else if (c != ' ') {
            printf("%c", c);
        }
    }
return 0;
}
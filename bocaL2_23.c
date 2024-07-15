#include<stdio.h>
    int main(){
        char ch, ch2;
        int cont1 = 0;
        int cont2 = 0;
        
        while(1){
            cont1 = 0;
            scanf("%c", &ch);
            if(ch == '('){
                while(1){
                    cont2++;
                    if(cont2 == 1){
                    printf("RESP:");
                }
                 scanf("%c", &ch2);
                 if(ch2 == '('){
                    cont1++;
                }
                if(ch2 == ')'){
                    cont1--;
                }
                if(cont1 == -1){
                    break;
                }
                
                printf("%c", ch2);
                }
            }
            if(ch == '.'){
                break;
            }
        }
        








        return 0;
    }